#pragma once
#include "BindingContext.h"
#include "Camera.h"
#include "Core.h"
#include "DxUtil.h"
#include "InputAction.h"
#include "Renderer.h"
#include "Types.h"
#include <DirectXMath.h>
#include <memory>
#include <vector>

class World;

struct PlayerMeshData
{
	std::vector<Vector3D> vertices;
	std::vector<uint16> indices;
};


class Player
{
public:

	Player(Vector3D position, World* worldRef);

public:

	void Tick();

	void UpdateCamera(float alpha, float deltaSeconds);

	void Move(Vector3D translation);

public:

	[[nodiscard]] FORCEINLINE const std::shared_ptr<BindingContext> GetInputBindings() const noexcept { return mInputControls; }

	[[nodiscard]] FORCEINLINE Camera& GetFPSCamera() { return *mFPSCamera.get(); }

	[[nodiscard]] FORCEINLINE DirectX::XMFLOAT4X4 GetWorldMatrix() const noexcept { return mWorldMatrix; }

	[[nodiscard]] FORCEINLINE Vector3D GetPosition() const noexcept { return mPosition; }

	[[nodiscard]] FORCEINLINE RenderData& GetRenderData() { return mRenderData; }

	[[nodiscard]] FORCEINLINE PlayerMeshData& GetMeshData() { return mMeshData; }

	[[nodiscard]] FORCEINLINE bool IsRenderDataDirty() const { return mRenderDataDirty; }

	bool SetRenderDataDirty(bool dirty) { return mRenderDataDirty = dirty; }

	[[nodiscard]] FORCEINLINE bool CanJump() const { return mOnGround && mJumpCooldownTicks == 0; }

	[[nodiscard]] FORCEINLINE bool CanSneak() const { return mOnGround; }

	[[nodiscard]] FORCEINLINE bool CanSprint() const { return !mSneaking; }

protected:

	void SetupInputBindings();

	void CreateBoxMesh();

	void UpdateWorldMatrix();

protected:

	void Jump();

	void ToggleFly();

	void SetSneaking(bool sneaking);

	void SetSprinting(bool sprinting);

	Vector2D GetHorizontalWorldVelocity(float strafe, float forward, float movementFactor, float forwardMovementFactor = 1.0f) const;

	void UpdatePosition();

	void MoveOnGround();

	void MoveFlying();

protected:

	bool mJumpInput = false;
	bool mSneakInput = false;
	bool mSprintInput = false;

	bool mToggleFlyStateInput = false;
	bool mAttemptToggleFlyState = false;
	float mAttemptToggleFlyStateTime = 0.0f;

protected:

	bool mFlying = false;
	bool mSprinting = false;
	bool mSneaking = false;

protected:

	bool mOnGround = false;	
	uint32 mJumpCooldownTicks = 0;
	static constexpr uint32 sJumpCooldownTicks = 10;
	static constexpr float sJumpSpeed = 0.42f;
	static constexpr float sJumpSprintBoost = 0.2f;

	float mRotationYaw = 0.0f;
	float mHeight = 1.8f;
	static constexpr float sBaseWidth = 0.6f;
	static constexpr float sBaseHeight = 1.8f;
	static constexpr float sSneakHeight = 1.5f;
	static constexpr float sHalfWidth = sBaseWidth / 2.0f;
	static constexpr Vector3D sDefaultFPSCameraOffset = { 0.0f, 1.62f, 0.0f };
	static constexpr Vector3D sSneakFPSCameraOffset = { 0.0f, 1.54f, 0.0f };
	static constexpr float sSneakingFPSCameraHeightOffset = -0.26f;
	static constexpr float sBaseFPSCameraFOV = 70.0f;
	static constexpr float sSprintFPSCameraFOV = 90.0f;
	//
	static constexpr float sDrag = 0.98f;
	static constexpr float sBaseIntertia = 0.91f;
	static constexpr float sBaseAcceleration = 0.16277136f;
	static constexpr float sGroundResistance = 0.1f;
	static constexpr float sAirResistance = 0.02f;
	static constexpr float sSprintMovementMultiplier = 1.3f;
	static constexpr float sSneakMovementMultiplier = 0.3f;
	static constexpr float sFlyMovementMultiplier = 2.5f;
	static constexpr float sGravityAcceleration = -0.08f;
	static constexpr float sFlyVerticalSpeed = 0.3f;

	static constexpr float sVerticalViewBobIntensity = 0.035f;
	static constexpr float sHorizontalViewBobIntensity = 0.01f;
	static constexpr float sViewBobSpeedModifier = 3.0f;


	//
	static constexpr float sMinimumAxisSpeed = 0.003f;

protected:

	Vector2D mMovementInput;
	Vector3D mFPSCameraOffset = sDefaultFPSCameraOffset;

	World* const mWorldRef = nullptr;
	Vector3D mPosition;
	Vector3D mPreviousPosition;

	Vector3D mVelocity;

	DirectX::XMFLOAT4X4 mWorldMatrix = DxUtil::Identity4x4();
	PlayerMeshData mMeshData;
	RenderData mRenderData;

	bool mRenderDataDirty = true;

	float mWalkDistance = 0.0f;
	float mViewBobTime = 0.0f;
	float mViewBobFactor = 0.0f;
	float mFOV = sBaseFPSCameraFOV;

protected:

	std::unique_ptr<Camera> mFPSCamera;

protected:

	std::shared_ptr<InputAction> mLookAction;
	std::shared_ptr<InputAction> mWalkAction;
	std::shared_ptr<InputAction> mPrimaryInteractAction;
	std::shared_ptr<InputAction> mSecondaryInteractAction;
	std::shared_ptr<InputAction> mJumpAction;
	std::shared_ptr<InputAction> mToggleFlyAction;
	std::shared_ptr<InputAction> mSprintAction;
	std::shared_ptr<InputAction> mSneakAction;
	std::shared_ptr<InputAction> mEscAction;
	std::shared_ptr<BindingContext> mInputControls;
};