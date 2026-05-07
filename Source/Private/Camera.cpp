#include "Camera.h"
#include <algorithm>
#include <cmath>
#include <DirectXMath.h>
#include <DirectXMathConvert.inl>
#include <DirectXMathMatrix.inl>
#include <DirectXMathMisc.inl>
#include <DirectXMathVector.inl>
#include <Types.h>

using namespace DirectX;

Camera::Camera(float aspectRatio, Vector3D position, Vector2D rotation, float fov)
	:
	mAspectRatio(aspectRatio),
	mPosition(position),
	mRotation(rotation),
	mFOV(fov)
{
	UpdateViewMatrix();
	UpdateProjectionMatrix();
}

Vector3D Camera::GetForward() const noexcept
{
	Vector3D forward = {
		std::cos(mRotation.x) * std::sin(mRotation.y),
		std::sin(mRotation.x),
		std::cos(mRotation.x) * std::cos(mRotation.y)
	};

	return forward.Normalize();
}

Vector3D Camera::GetRight() const noexcept
{
	const Vector3D forward = GetForward();
	const Vector3D up = { 0.0f, 1.0f, 0.0f };

	return forward.Cross(up).Normalize();
}

void Camera::Translate(Vector3D translation)
{
	Translate(translation.x, translation.y, translation.z);
}

void Camera::Translate(float x, float y, float z)
{
	const XMVECTOR qRotation = XMQuaternionRotationRollPitchYaw(mRotation.x, mRotation.y, 0.0f);

	// Canonical axes
	XMVECTOR forward = XMVector3Rotate(XMVectorSet(0, 0, 1, 0), qRotation);
	XMVECTOR right = XMVector3Rotate(XMVectorSet(1, 0, 0, 0), qRotation);
	XMVECTOR up = XMVector3Rotate(XMVectorSet(0, 1, 0, 0), qRotation);

	// Scale each axis by the requested translation
	XMVECTOR move =
		XMVectorScale(forward, z) +
		XMVectorScale(right, x) +
		XMVectorScale(up, y);

	// Add to position
	XMVECTOR position = XMVectorSet(mPosition.x, mPosition.y, mPosition.z, 1.0f);
	position = XMVectorAdd(position, move);

	XMFLOAT3 pos;
	XMStoreFloat3(&pos, position);

	mPosition = Vector3D(pos.x, pos.y, pos.z);

	UpdateViewMatrix();
}

void Camera::SetPosition(Vector3D position)
{
	mPosition = position;
	UpdateViewMatrix();
}

void Camera::Rotate(Vector2D rotation)
{
	Rotate(rotation.x, rotation.y);
}

void Camera::Rotate(float pitch, float yaw)
{
	mRotation.x = std::clamp(mRotation.x + pitch, -XM_PIDIV2 + 0.01f, XM_PIDIV2 - 0.01f);
	mRotation.y = std::fmod(mRotation.y + yaw + XM_PI, XM_2PI) - XM_PI;

	UpdateViewMatrix();
}

void Camera::SetRotation(Vector2D rotation)
{
	mRotation.x = std::clamp(rotation.x, -XM_PIDIV2 + 0.01f, XM_PIDIV2 - 0.01f);
	mRotation.y = std::fmod(rotation.y + XM_PI, XM_2PI) - XM_PI;

	UpdateViewMatrix();
}

void Camera::SetAspectRatio(float aspectRatio)
{
	mAspectRatio = aspectRatio;
	UpdateProjectionMatrix();
}

void Camera::SetFOV(float fov)
{
	mFOV = fov;
	UpdateProjectionMatrix();
}

void Camera::UpdateViewMatrix()
{
	const XMFLOAT3 position = { mPosition.x, mPosition.y, mPosition.z };
	const XMVECTOR qRotation = XMQuaternionRotationRollPitchYaw(mRotation.x, mRotation.y, 0.0f);

	const XMVECTOR eye = XMLoadFloat3(&position);
	const XMVECTOR forward = XMVector3Rotate(XMVectorSet(0, 0, 1, 0), qRotation);
	const XMVECTOR up = XMVector3Rotate(XMVectorSet(0, 1, 0, 0), qRotation);


	XMStoreFloat4x4(&mView, XMMatrixLookToLH(eye, forward, up));
}

void Camera::UpdateProjectionMatrix()
{
	XMMATRIX projection = XMMatrixPerspectiveFovLH(
		XMConvertToRadians(mFOV / 2.0f),
		mAspectRatio,
		0.1f,
		1000.0f
	);
	XMStoreFloat4x4(&mProjection, projection);
}
