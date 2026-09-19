#include "App.h"
#include "BindingContext.h"
#include "Camera.h"
#include "DLog.h"
#include "DMath.h"
#include "InputAction.h"
#include "InputModifier.h"
#include "InputTrigger.h"
#include "Player.h"
#include "Types.h"
#include "World.h"
#include <algorithm>
#include <BlockType.h>
#include <cmath>
#include <DirectXMath.h>
#include <DirectXMathConvert.inl>
#include <DirectXMathMatrix.inl>
#include <limits>
#include <memory>

#define LOG_SPEED 0


[[nodiscard]] static constexpr float GetBlockFriction(EBlockType block)
{
	switch (block)
	{
	case EBlockType::Air:
		return 1.0f;
	case EBlockType::BlueIce:
		return 0.989f;
	case EBlockType::Ice:
	case EBlockType::PackedIce:
		return 0.98f;
	case EBlockType::SlimeBlock:
		return 0.8f;
	}
	return 0.6f;
}

[[nodiscard]] static Vector2D ConvertLocalToWorldVector(Vector2D localVector, float yaw)
{
	const float sinYaw = std::sin(yaw);
	const float cosYaw = std::cos(yaw);

	return Vector2D(
		localVector.y * sinYaw + localVector.x * cosYaw,
		localVector.y * cosYaw - localVector.x * sinYaw
	);
}


Player::Player(Vector3D position, World* worldRef)
	:
	mPosition(position),
	mWorldRef(worldRef),
	mFPSCamera(std::make_unique<Camera>(16.0f / 9.0f, mPosition + mFPSCameraOffset, Vector2D::Zero(), sBaseFPSCameraFOV))
{
	SetupInputBindings();
	CreateBoxMesh();
	UpdateWorldMatrix();
}

void Player::Tick()
{
	if (mToggleFlyStateInput)
	{
		ToggleFly();
		mToggleFlyStateInput = false;
	}

	if (mFlying && mOnGround)
	{
		ToggleFly();
	}

	if (!mJumpInput)
	{
		mJumpCooldownTicks = 0;
	}

	if (mJumpCooldownTicks > 0)
	{
		mJumpCooldownTicks--;
	}

	UpdatePosition();

	mMovementInput = { 0.0f, 0.0f };
	UpdateWorldMatrix();
}

void Player::UpdateCamera(float alpha, float deltaSeconds)
{
	// Interpolate between last tick and current tick
	Vector3D targetPosition = mPosition + mFPSCameraOffset;
	Vector3D startPosition = mPreviousPosition + mFPSCameraOffset;

	Vector3D cameraPosition = DMath::Lerp(startPosition, targetPosition, alpha);


	float t = 1.0f - std::exp(-10.0f * deltaSeconds);


	const float walkSpeed = mWalkDistance * 20.0f;
	const float targetViewBobFactor = (walkSpeed > 0.0f) ? 1.0f : 0.0f;

	if (walkSpeed > 0.0f)
	{
		mViewBobTime += deltaSeconds * walkSpeed * sViewBobSpeedModifier;
		mViewBobTime = std::fmod(mViewBobTime, DirectX::XM_2PI);
	}

	mViewBobFactor = std::lerp(mViewBobFactor, targetViewBobFactor, t);
	mViewBobFactor = DMath::ClampSmall(mViewBobFactor, 0.001f);

	const float xOffset = cos(mViewBobTime) * sHorizontalViewBobIntensity * mViewBobFactor;
	const float yOffset = sin(mViewBobTime) * sVerticalViewBobIntensity * mViewBobFactor;

	Vector3D right = mFPSCamera->GetRight();
	Vector3D up = { 0.0f, 1.0f, 0.0f };
	Vector3D cameraViewBobOffset = right * xOffset + up * yOffset;

	float targetFOV = mSprinting ? sSprintFPSCameraFOV : sBaseFPSCameraFOV;
	mFOV = std::lerp(mFOV, targetFOV, t);

	cameraPosition += cameraViewBobOffset;

	mFPSCamera->SetPosition(cameraPosition);
	mFPSCamera->SetFOV(mFOV);
}

void Player::Move(Vector3D translation)
{
	constexpr float separation = 0.001f;
	mOnGround = false;
	mPreviousPosition = mPosition;

#pragma region Y-axis

	mPosition.y += translation.y;

	bool b1OnGround = false;
	bool b2OnGround = false;
	bool b3OnGround = false;
	bool b4OnGround = false;

	if (translation.y < 0)
	{
		Vector3D b1 = { mPosition.x - sHalfWidth, mPosition.y, mPosition.z - sHalfWidth };
		Vector3D b2 = { mPosition.x - sHalfWidth, mPosition.y, mPosition.z + sHalfWidth };
		Vector3D b3 = { mPosition.x + sHalfWidth, mPosition.y, mPosition.z - sHalfWidth };
		Vector3D b4 = { mPosition.x + sHalfWidth, mPosition.y, mPosition.z + sHalfWidth };

		b1OnGround = mWorldRef->GetBlockAt(b1) != EBlockType::Air;
		b2OnGround = mWorldRef->GetBlockAt(b2) != EBlockType::Air;
		b3OnGround = mWorldRef->GetBlockAt(b3) != EBlockType::Air;
		b4OnGround = mWorldRef->GetBlockAt(b4) != EBlockType::Air;

		if (b1OnGround || b2OnGround || b3OnGround || b4OnGround)
		{
			mPosition.y = std::ceil(mPosition.y);
			mVelocity.y = 0.0f;
			mOnGround = true;
		}
	}
	else if (translation.y > 0)
	{
		Vector3D t1 = { mPosition.x - sHalfWidth, mPosition.y + mHeight, mPosition.z - sHalfWidth };
		Vector3D t2 = { mPosition.x - sHalfWidth, mPosition.y + mHeight, mPosition.z + sHalfWidth };
		Vector3D t3 = { mPosition.x + sHalfWidth, mPosition.y + mHeight, mPosition.z - sHalfWidth };
		Vector3D t4 = { mPosition.x + sHalfWidth, mPosition.y + mHeight, mPosition.z + sHalfWidth };

		for (const auto& t : { t1, t2, t3, t4 })
		{
			if (mWorldRef->GetBlockAt(t) != EBlockType::Air)
			{
				mPosition.y = std::floor(mPosition.y);
				mVelocity.y = 0.0f;
				//DLog::Log("Positive Y-axis collision!");
				break;
			}
		}
	}

#pragma endregion

#pragma region X-axis

	mPosition.x += translation.x;

	if (translation.x < 0)
	{
		Vector3D l1 = { mPosition.x - sHalfWidth, mPosition.y, mPosition.z - sHalfWidth };
		Vector3D l2 = { mPosition.x - sHalfWidth, mPosition.y + mHeight, mPosition.z + sHalfWidth };
		Vector3D l3 = { mPosition.x - sHalfWidth, mPosition.y + mHeight, mPosition.z - sHalfWidth };
		Vector3D l4 = { mPosition.x - sHalfWidth, mPosition.y, mPosition.z + sHalfWidth };

		for (const auto& l : { l1, l2, l3, l4 })
		{
			if (mWorldRef->GetBlockAt(l) != EBlockType::Air)
			{
				mPosition.x = std::ceil(mPosition.x - sHalfWidth) + sHalfWidth + separation;
				mVelocity.x = 0.0f;
				//DLog::Log("Negative X-axis collision!");
				break;
			}
		}
	}
	else if (translation.x > 0)
	{
		Vector3D r1 = { mPosition.x + sHalfWidth, mPosition.y, mPosition.z - sHalfWidth };
		Vector3D r2 = { mPosition.x + sHalfWidth, mPosition.y + mHeight, mPosition.z + sHalfWidth };
		Vector3D r3 = { mPosition.x + sHalfWidth, mPosition.y + mHeight, mPosition.z - sHalfWidth };
		Vector3D r4 = { mPosition.x + sHalfWidth, mPosition.y, mPosition.z + sHalfWidth };

		for (const auto& r : { r1, r2, r3, r4 })
		{
			if (mWorldRef->GetBlockAt(r) != EBlockType::Air)
			{
				mPosition.x = std::floor(mPosition.x + sHalfWidth) - sHalfWidth - separation;
				mVelocity.x = 0.0f;
				//DLog::Log("Positive X-axis collision!");
				break;
			}
		}
	}

#pragma endregion

#pragma region Z-axis

	mPosition.z += translation.z;

	if (translation.z < 0)
	{
		Vector3D b1 = { mPosition.x - sHalfWidth, mPosition.y, mPosition.z - sHalfWidth };
		Vector3D b2 = { mPosition.x - sHalfWidth, mPosition.y + mHeight, mPosition.z - sHalfWidth };
		Vector3D b3 = { mPosition.x + sHalfWidth, mPosition.y + mHeight, mPosition.z - sHalfWidth };
		Vector3D b4 = { mPosition.x + sHalfWidth, mPosition.y, mPosition.z - sHalfWidth };

		for (const auto& b : { b1, b2, b3, b4 })
		{
			if (mWorldRef->GetBlockAt(b) != EBlockType::Air)
			{
				mPosition.z = std::ceil(mPosition.z - sHalfWidth) + sHalfWidth + separation;
				mVelocity.z = 0.0f;
				//DLog::Log("Negative Z-axis collision!");
				break;
			}
		}
	}
	else if (translation.z > 0)
	{
		Vector3D f1 = { mPosition.x - sHalfWidth, mPosition.y, mPosition.z + sHalfWidth };
		Vector3D f2 = { mPosition.x - sHalfWidth, mPosition.y + mHeight, mPosition.z + sHalfWidth };
		Vector3D f3 = { mPosition.x + sHalfWidth, mPosition.y + mHeight, mPosition.z + sHalfWidth };
		Vector3D f4 = { mPosition.x + sHalfWidth, mPosition.y, mPosition.z + sHalfWidth };

		for (const auto& f : { f1, f2, f3, f4 })
		{
			if (mWorldRef->GetBlockAt(f) != EBlockType::Air)
			{
				mPosition.z = std::floor(mPosition.z + sHalfWidth) - sHalfWidth - separation;
				mVelocity.z = 0.0f;
				//DLog::Log("Positive Z-axis collision!");
				break;
			}
		}
	}

#pragma endregion

#pragma region Sneaking

	if (mSneaking && mOnGround)
	{
		Vector3D b1 = { mPosition.x - sHalfWidth, mPreviousPosition.y + translation.y, mPosition.z - sHalfWidth };
		Vector3D b2 = { mPosition.x - sHalfWidth, mPreviousPosition.y + translation.y, mPosition.z + sHalfWidth };
		Vector3D b3 = { mPosition.x + sHalfWidth, mPreviousPosition.y + translation.y, mPosition.z - sHalfWidth };
		Vector3D b4 = { mPosition.x + sHalfWidth, mPreviousPosition.y + translation.y, mPosition.z + sHalfWidth };

		const bool newB1OnGround = mWorldRef->GetBlockAt(b1) != EBlockType::Air;
		const bool newB2OnGround = mWorldRef->GetBlockAt(b2) != EBlockType::Air;
		const bool newB3OnGround = mWorldRef->GetBlockAt(b3) != EBlockType::Air;
		const bool newB4OnGround = mWorldRef->GetBlockAt(b4) != EBlockType::Air;



		// Assume that it is impossible for the player to have walked off with all of the points at the same time
		// which would be possible at higher speeds.
		if (!newB1OnGround && !newB2OnGround && !newB3OnGround && !newB4OnGround)
		{
			if (b1OnGround && b2OnGround)
			{
				mPosition.x = std::floor(mPosition.x) + sHalfWidth - separation;
				mVelocity.x = 0.0f;
				//DLog::Log("Left ledge!");
			}
			else if (b1OnGround && b3OnGround)
			{
				mPosition.z = std::floor(mPosition.z) + sHalfWidth - separation;
				mVelocity.z = 0.0f;
				//DLog::Log("Back ledge!");
			}
			else if (b1OnGround)
			{
				auto prevBlockCoords = PositionToBlockCoordinates({ mPreviousPosition.x - sHalfWidth, mPreviousPosition.y + translation.y, mPreviousPosition.z - sHalfWidth });
				auto newBlockCoords = PositionToBlockCoordinates(b1);

				if (newBlockCoords.x != prevBlockCoords.x)
				{
					mPosition.x = std::floor(mPosition.x) + sHalfWidth - separation;
					mVelocity.x = 0.0f;
				}
				if (newBlockCoords.z != prevBlockCoords.z)
				{
					mPosition.z = std::floor(mPosition.z) + sHalfWidth - separation;
					mVelocity.z = 0.0f;
				}
				//DLog::Log("Left & Back ledge!");
			}
			else if (b2OnGround && b4OnGround)
			{
				mPosition.z = std::ceil(mPosition.z) - sHalfWidth + separation;
				mVelocity.z = 0.0f;
				//DLog::Log("Forward ledge!");
			}
			else if (b2OnGround)
			{
				auto prevBlockCoords = PositionToBlockCoordinates({ mPreviousPosition.x - sHalfWidth, mPreviousPosition.y + translation.y, mPreviousPosition.z + sHalfWidth });
				auto newBlockCoords = PositionToBlockCoordinates(b2);

				if (newBlockCoords.x != prevBlockCoords.x)
				{
					mPosition.x = std::floor(mPosition.x) + sHalfWidth - separation;
					mVelocity.x = 0.0f;
				}
				if (newBlockCoords.z != prevBlockCoords.z)
				{
					mPosition.z = std::ceil(mPosition.z) - sHalfWidth + separation;
					mVelocity.z = 0.0f;
				}
				//DLog::Log("Left & Forward ledge!");
			}
			else if (b3OnGround && b4OnGround)
			{
				mPosition.x = std::ceil(mPosition.x) - sHalfWidth + separation;
				mVelocity.x = 0.0f;
				//DLog::Log("Right ledge!");
			}
			else if (b3OnGround)
			{
				auto prevBlockCoords = PositionToBlockCoordinates({ mPreviousPosition.x + sHalfWidth, mPreviousPosition.y + translation.y, mPreviousPosition.z - sHalfWidth });
				auto newBlockCoords = PositionToBlockCoordinates(b3);

				if (newBlockCoords.x != prevBlockCoords.x)
				{
					mPosition.x = std::ceil(mPosition.x) - sHalfWidth + separation;
					mVelocity.x = 0.0f;
				}
				if (newBlockCoords.z != prevBlockCoords.z)
				{
					mPosition.z = std::floor(mPosition.z) + sHalfWidth - separation;
					mVelocity.z = 0.0f;
				}
				//DLog::Log("Right & Back ledge!");
			}
			else if (b4OnGround)
			{
				auto prevBlockCoords = PositionToBlockCoordinates({ mPreviousPosition.x + sHalfWidth, mPreviousPosition.y + translation.y, mPreviousPosition.z + sHalfWidth });
				auto newBlockCoords = PositionToBlockCoordinates(b4);

				if (newBlockCoords.x != prevBlockCoords.x)
				{
					mPosition.x = std::ceil(mPosition.x) - sHalfWidth + separation;
					mVelocity.x = 0.0f;
				}
				if (newBlockCoords.z != prevBlockCoords.z)
				{
					mPosition.z = std::ceil(mPosition.z) - sHalfWidth + separation;
					mVelocity.z = 0.0f;
				}
				//DLog::Log("Right & Forward ledge!");
			}
		}
	}
#pragma endregion
}


void Player::SetupInputBindings()
{
	mLookAction = std::make_shared<InputAction>("PlayerLook", EActionValueType::Vector2D);
	mWalkAction = std::make_shared<InputAction>("PlayerWalk", EActionValueType::Vector2D);
	mJumpAction = std::make_shared<InputAction>("PlayerJump");
	mSneakAction = std::make_shared<InputAction>("PlayerSneak");
	mSprintAction = std::make_shared<InputAction>("PlayerSprint");
	mPrimaryInteractAction = std::make_shared<InputAction>("PlayerPrimaryInteract");
	mSecondaryInteractAction = std::make_shared<InputAction>("PlayerSecondaryInteract");
	mToggleFlyAction = std::make_shared<InputAction>("PlayerToggleFly");
	mEscAction = std::make_shared<InputAction>("Player ESC");

	mInputControls = std::make_shared<BindingContext>(
		ActionMapping{
			mLookAction, {
				Mapping{
					EKey::MouseX,
					{ },
					{ }
				},
				Mapping{
					EKey::MouseY,
					{ Modifiers::ReorderAxes(Axes::YXZ) },
					{ }
				}
			}
		},
		ActionMapping{
			mWalkAction, {
				Mapping{
					EKey::W,
					{ Modifiers::ReorderAxes(Axes::YXZ) },
					{ }
				},
				Mapping{
					EKey::S,
					{ Modifiers::ReorderAxes(Axes::YXZ), Modifiers::Negate(false, true, false) },
					{ }
				},
				Mapping{
					EKey::A,
					{ Modifiers::Negate(true, false, false) },
					{ }
				},
				Mapping{
					EKey::D,
					{ },
					{ }
				}
			},
		},
		ActionMapping{
			mSneakAction, {
				Mapping{
					EKey::LeftShift,
					{ },
					{ }
				}
			}
		},
		ActionMapping{
			mSprintAction, {
				Mapping{
					EKey::LeftCtrl,
					{ },
					{ }
				}
			}
		},
		ActionMapping{
			mJumpAction, {
				Mapping{
					EKey::Space,
					{ },
					{ }
				}
			}
		},
		ActionMapping{
			mPrimaryInteractAction, {
				Mapping{
					EKey::MouseLeft,
					{ },
					{ }
				}
			}
		},
		ActionMapping{
			mSecondaryInteractAction, {
				Mapping{
					EKey::MouseRight,
					{},
					{}
				}
			}
		},
		ActionMapping{
			mToggleFlyAction, {
				Mapping{
					EKey::Space,
					{},
					{ Triggers::Tap() }
				}
			}
		},
		ActionMapping{
			mEscAction, {
				Mapping{
					EKey::Escape,
					{},
					{}
				}
			}
		}
	);


	mLookAction->BindCallback(EActionState::Triggered,
		[this](InputActionValue value)
		{
			const auto vec2 = value.Get<Vector2D>() * 0.5f;
			const float yaw = DirectX::XMConvertToRadians(vec2.x);
			const float pitch = DirectX::XMConvertToRadians(vec2.y);

			mFPSCamera->Rotate(pitch, yaw);
			mRotationYaw = mFPSCamera->GetRotation().y;
		}
	);

	mWalkAction->BindCallback(EActionState::Triggered,
		[this](InputActionValue value)
		{
			const auto vec2 = value.Get<Vector2D>();
			mMovementInput.x = vec2.x != 0.0f ? std::copysign(1.0f, vec2.x) : 0.0f;
			mMovementInput.y = vec2.y != 0.0f ? std::copysign(1.0f, vec2.y) : 0.0f;

			//mMovementInput += value.Get<Vector2D>();
		}
	);

	mWalkAction->BindCallback(EActionState::Completed,
		[this]()
		{
			mMovementInput.x = 0.0f;
			mMovementInput.y = 0.0f;
		}
	);

	mSprintAction->BindCallback(EActionState::Started,
		[this]()
		{
			mSprintInput = true;
		}
	);

	mSprintAction->BindCallback(EActionState::Completed,
		[this]()
		{
			mSprintInput = false;
		}
	);

	mJumpAction->BindCallback(EActionState::Started,
		[this]()
		{
			mJumpInput = true;
		}
	);

	mJumpAction->BindCallback(EActionState::Completed,
		[this]()
		{
			mJumpInput = false;
		}
	);

	mSneakAction->BindCallback(EActionState::Started,
		[this]()
		{
			mSneakInput = true;
		}
	);

	mSneakAction->BindCallback(EActionState::Completed,
		[this]()
		{
			mSneakInput = false;
		}
	);

	mToggleFlyAction->BindCallback(EActionState::Started,
		[this]([[maybe_unused]] InputActionValue value, float deltaSeconds)
		{
			//DLog::Log("Started!");
			if (mAttemptToggleFlyState)
			{
				const float t = App::Get().GetCurrentSeconds() - mAttemptToggleFlyStateTime - deltaSeconds;
				constexpr float timeForSecondInput = 0.3f;
				if (t < timeForSecondInput)
				{
					mToggleFlyStateInput = true;
					DLog::Log("Toggle fly started!, t = {}", t);
					mAttemptToggleFlyState = false;
				}
				else
				{
					DLog::Log("Toggle fly failed!, t = {}", t);
					mAttemptToggleFlyState = false;
				}
			}
			else
			{
				mAttemptToggleFlyState = true;
				mAttemptToggleFlyStateTime = App::Get().GetCurrentSeconds();
			}

		}
	);

	mToggleFlyAction->BindCallback(EActionState::Canceled,
		[this]()
		{
			mAttemptToggleFlyState = false; // if the tap was failed (i.e. the input was held instead of tapped, cancel the toggle fly attempt)
			mAttemptToggleFlyStateTime = 0.0f;
			//DLog::Log("Canceled!");
		}
	);

	mEscAction->BindCallback(EActionState::Started,
		[]()
		{
			App::Get().UnlockCursor();
			App::Get().AppPause();
		}
	);
}

void Player::CreateBoxMesh()
{
	mMeshData.vertices.reserve(24);

	constexpr float halfWidht = sBaseWidth / 2.0f;

	// Front face
	mMeshData.vertices.push_back(Vector3D{ -halfWidht, 0.0f, -halfWidht });
	mMeshData.vertices.push_back(Vector3D{ -halfWidht, sBaseHeight, -halfWidht });
	mMeshData.vertices.push_back(Vector3D{ halfWidht, sBaseHeight, -halfWidht });
	mMeshData.vertices.push_back(Vector3D{ halfWidht, 0.0f, -halfWidht });

	// Back face
	mMeshData.vertices.push_back(Vector3D{ -halfWidht, 0.0f, halfWidht });
	mMeshData.vertices.push_back(Vector3D{ halfWidht, 0.0f, halfWidht });
	mMeshData.vertices.push_back(Vector3D{ halfWidht, sBaseHeight, halfWidht });
	mMeshData.vertices.push_back(Vector3D{ -halfWidht, sBaseHeight, halfWidht });

	// Top face
	mMeshData.vertices.push_back(Vector3D{ -halfWidht, sBaseHeight, -halfWidht });
	mMeshData.vertices.push_back(Vector3D{ -halfWidht, sBaseHeight, halfWidht });
	mMeshData.vertices.push_back(Vector3D{ halfWidht, sBaseHeight, halfWidht });
	mMeshData.vertices.push_back(Vector3D{ halfWidht, sBaseHeight, -halfWidht });

	// Bottom face
	mMeshData.vertices.push_back(Vector3D{ -halfWidht, 0.0f, -halfWidht });
	mMeshData.vertices.push_back(Vector3D{ halfWidht, 0.0f, -halfWidht });
	mMeshData.vertices.push_back(Vector3D{ halfWidht, 0.0f, halfWidht });
	mMeshData.vertices.push_back(Vector3D{ -halfWidht, 0.0f, halfWidht });

	// Left face
	mMeshData.vertices.push_back(Vector3D{ -halfWidht, 0.0f, halfWidht });
	mMeshData.vertices.push_back(Vector3D{ -halfWidht, sBaseHeight, halfWidht });
	mMeshData.vertices.push_back(Vector3D{ -halfWidht, sBaseHeight, -halfWidht });
	mMeshData.vertices.push_back(Vector3D{ -halfWidht, 0.0f, -halfWidht });

	// Right face
	mMeshData.vertices.push_back(Vector3D{ halfWidht, 0.0f, -halfWidht });
	mMeshData.vertices.push_back(Vector3D{ halfWidht, sBaseHeight, -halfWidht });
	mMeshData.vertices.push_back(Vector3D{ halfWidht, sBaseHeight, halfWidht });
	mMeshData.vertices.push_back(Vector3D{ halfWidht, 0.0f, halfWidht });

	mMeshData.indices.resize(36);

	// Fill in the front face index data
	mMeshData.indices[0] = 0;
	mMeshData.indices[1] = 1;
	mMeshData.indices[2] = 2;

	mMeshData.indices[3] = 0;
	mMeshData.indices[4] = 2;
	mMeshData.indices[5] = 3;

	// Fill in the back face index data
	mMeshData.indices[6] = 4;
	mMeshData.indices[7] = 5;
	mMeshData.indices[8] = 6;

	mMeshData.indices[9] = 4;
	mMeshData.indices[10] = 6;
	mMeshData.indices[11] = 7;

	// Fill in the top face index data
	mMeshData.indices[12] = 8;
	mMeshData.indices[13] = 9;
	mMeshData.indices[14] = 10;

	mMeshData.indices[15] = 8;
	mMeshData.indices[16] = 10;
	mMeshData.indices[17] = 11;

	// Fill in the bottom face index data
	mMeshData.indices[18] = 12;
	mMeshData.indices[19] = 13;
	mMeshData.indices[20] = 14;

	mMeshData.indices[21] = 12;
	mMeshData.indices[22] = 14;
	mMeshData.indices[23] = 15;

	// Fill in the left face index data
	mMeshData.indices[24] = 16;
	mMeshData.indices[25] = 17;
	mMeshData.indices[26] = 18;

	mMeshData.indices[27] = 16;
	mMeshData.indices[28] = 18;
	mMeshData.indices[29] = 19;

	// Fill in the right face index data
	mMeshData.indices[30] = 20;
	mMeshData.indices[31] = 21;
	mMeshData.indices[32] = 22;

	mMeshData.indices[33] = 20;
	mMeshData.indices[34] = 22;
	mMeshData.indices[35] = 23;

}

void Player::UpdateWorldMatrix()
{
	DirectX::XMMATRIX world = DirectX::XMMatrixTranslation(mPosition.x, mPosition.y, mPosition.z);
	DirectX::XMStoreFloat4x4(&mWorldMatrix, world);
}

void Player::Jump()
{
	mVelocity.y = sJumpSpeed;
	mJumpCooldownTicks = sJumpCooldownTicks;

	if (mSprinting)
	{
		mVelocity.x -= std::sin(-mRotationYaw) * sJumpSprintBoost;
		mVelocity.z += std::cos(-mRotationYaw) * sJumpSprintBoost;
	}
}

void Player::ToggleFly()
{
	mFlying = !mFlying;
	mVelocity.y = 0.0f;
}

void Player::SetSneaking(bool sneaking)
{
	if (mSneaking == sneaking)
	{
		return;
	}

	mSneaking = sneaking;

	if (mSneaking)
	{
		mHeight = sSneakHeight;
		mFPSCameraOffset = sSneakFPSCameraOffset;
	}
	else
	{
		mHeight = sBaseHeight;
		mFPSCameraOffset = sDefaultFPSCameraOffset;
	}
}

void Player::SetSprinting(bool sprinting)
{
	if (mSprinting == sprinting)
	{
		return;
	}

	mSprinting = sprinting;
}

Vector2D Player::GetHorizontalWorldVelocity(float strafe, float forward, float movementFactor, float forwardMovementFactor) const
{
	const float lengthSquared = strafe * strafe + forward * forward;

	if (lengthSquared >= std::numeric_limits<float>::epsilon())
	{
		const float length = std::max(std::sqrt(lengthSquared), 1.0f);

		movementFactor /= length;
		strafe *= movementFactor;
		forward *= movementFactor * forwardMovementFactor;

		float sinYaw = std::sin(mRotationYaw);
		float cosYaw = std::cos(mRotationYaw);

		return Vector2D(
			forward * sinYaw + strafe * cosYaw,
			forward * cosYaw - strafe * sinYaw
		);
	}

	return Vector2D::Zero();
}


void Player::UpdatePosition()
{
	if (mFlying)
	{
		MoveFlying();
	}
	else
	{
		MoveOnGround();
	}

	float walkDistance = 0.0f;
	if (mOnGround)
	{
		Vector2D walkMovement = { mPosition.x - mPreviousPosition.x, mPosition.z - mPreviousPosition.z };
		walkDistance = walkMovement.Length();
	}
	mWalkDistance = walkDistance;
}

void Player::MoveOnGround()
{
	if (mJumpInput && CanJump())
	{
		Jump();
	}

	SetSneaking(mSneakInput && CanSneak());
	SetSprinting(mSprintInput && mMovementInput.y > 0.0f && CanSprint());


	Vector2D groundAcceleration = mMovementInput * sDrag;

	if (mSneaking)
	{
		groundAcceleration *= sSneakMovementMultiplier;
	}

	if (groundAcceleration.LengthSquared() > 1.0f)
	{
		groundAcceleration.Normalize();
	}

	constexpr float friction = 0.6f; // Hardcoded for now, in the future decide based on the block we are on (hard to define considering we could be standing on multiple blocks)
	const float inertia = mOnGround ? sBaseIntertia * friction : sBaseIntertia;
	const float acceleration = 0.21600002f / (friction * friction * friction); // evaluates to 1.0f when default friction (0.6f)
	float movementFactor = mOnGround ? sGroundResistance * acceleration : sAirResistance;

	groundAcceleration *= movementFactor;

	if (mSprinting)
	{
		groundAcceleration.y *= sSprintMovementMultiplier;
	}

	groundAcceleration = ConvertLocalToWorldVector(groundAcceleration, mRotationYaw);

	mVelocity.x += groundAcceleration.x;
	mVelocity.z += groundAcceleration.y;


	mVelocity = {
		DMath::ClampSmall(mVelocity.x, sMinimumAxisSpeed),
		DMath::ClampSmall(mVelocity.y, sMinimumAxisSpeed),
		DMath::ClampSmall(mVelocity.z, sMinimumAxisSpeed)
	};

#if LOG_SPEED
	const float speed = std::sqrt(mVelocity.x * mVelocity.x + mVelocity.z * mVelocity.z);
	DLog::Log("Velocity: {}, Speed: {}mpt ({}mps), OnGround: {}, Flying: {}", mVelocity, speed, speed * 20.0f, mOnGround, mFlying);
#endif

	Move(mVelocity);

	mVelocity.x *= inertia;
	mVelocity.z *= inertia;
	mVelocity.y += sGravityAcceleration;
	mVelocity.y *= sDrag;
}

void Player::MoveFlying()
{
	Vector2D groundAcceleration = mMovementInput * sDrag;

	if (groundAcceleration.LengthSquared() > 1.0f)
	{
		groundAcceleration.Normalize();
	}

	float movementFactor = sFlyMovementMultiplier * sAirResistance;

	if (mSprintInput)
	{
		movementFactor *= 2.0f;
	}

	groundAcceleration *= movementFactor;

	groundAcceleration = ConvertLocalToWorldVector(groundAcceleration, mRotationYaw);

	mVelocity.x += groundAcceleration.x;
	mVelocity.z += groundAcceleration.y;

	if (mJumpInput)
	{
		mVelocity.y = sFlyVerticalSpeed;
	}
	else if (mSneakInput)
	{
		mVelocity.y = -sFlyVerticalSpeed;
	}

	mVelocity.y *= sDrag;

	mVelocity = {
		DMath::ClampSmall(mVelocity.x, sMinimumAxisSpeed),
		DMath::ClampSmall(mVelocity.y, sMinimumAxisSpeed),
		DMath::ClampSmall(mVelocity.z, sMinimumAxisSpeed)
	};

#if LOG_SPEED
	const float speed = std::sqrt(mVelocity.x * mVelocity.x + mVelocity.z * mVelocity.z);
	DLog::Log("Velocity: {}, Speed: {}mpt ({}mps), OnGround: {}, Flying: {}", mVelocity, speed, speed * 20.0f, mOnGround, mFlying);
#endif

	Move(mVelocity);

	mVelocity *= sBaseIntertia;
}
