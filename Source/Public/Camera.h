#pragma once
#include "Core.h"
#include "DxUtil.h"
#include "Types.h"
#include <DirectXMath.h>

class Camera
{
public:

	Camera(float aspectRatio, Vector3D position = Vector3D::Zero(), Vector2D rotation = Vector2D::Zero(), float FOV = 90.0f);

public:

	[[nodiscard]] FORCEINLINE constexpr DirectX::XMFLOAT4X4 GetViewMatrix() const noexcept
	{
		return mView;
	}

	[[nodiscard]] FORCEINLINE constexpr DirectX::XMFLOAT4X4 GetProjectionMatrix() const noexcept
	{
		return mProjection;
	}

	[[nodiscard]] FORCEINLINE constexpr Vector3D GetPosition() const noexcept
	{
		return mPosition;
	}

	[[nodiscard]] FORCEINLINE constexpr Vector2D GetRotation() const noexcept
	{
		return mRotation;
	}

	[[nodiscard]] Vector3D GetForward() const noexcept;

	[[nodiscard]] Vector3D GetRight() const noexcept;

public:

	void Translate(Vector3D translation);

	void Translate(float x, float y, float z);

	void SetPosition(Vector3D position);

	void Rotate(Vector2D rotation);

	void Rotate(float pitch, float yaw);

	void SetRotation(Vector2D rotation);

	void SetAspectRatio(float aspectRatio);

	void SetFOV(float FOV);

protected:

	void UpdateViewMatrix();

	void UpdateProjectionMatrix();

protected:

	float mAspectRatio;

	float mFOV;

	Vector3D mPosition;

	Vector2D mRotation;

	DirectX::XMFLOAT4X4 mView = DxUtil::Identity4x4();

	DirectX::XMFLOAT4X4 mProjection = DxUtil::Identity4x4();
};