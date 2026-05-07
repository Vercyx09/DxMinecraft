#pragma once

#include "InputAction.h"
#include "Types.h"
#include <memory>

class InputModifier
{

public:

	virtual ~InputModifier() = default;

	[[nodiscard]] virtual InputActionValue ModifyValue(InputActionValue value, EActionValueType valueType) const = 0;

};

enum class Axes : uint8
{
	XYZ,
	XZY,
	YXZ,
	YZX,
	ZXY,
	ZYX,
};


class Negate : public InputModifier
{
public:

	Negate(bool x = true, bool y = true, bool z = true)
		:
		x(x),
		y(y),
		z(z)
	{
	}

	[[nodiscard]] virtual InputActionValue ModifyValue(InputActionValue value, EActionValueType valueType) const override
	{
		if (valueType == EActionValueType::Boolean)
		{
			return InputActionValue(!value.Get<bool>());
		}
		else
		{
			auto vec3 = value.Get<Vector3D>();
			return InputActionValue(x ? -vec3.x : vec3.x, y ? -vec3.y : vec3.y, z ? -vec3.z : vec3.z);
		}
	}

protected:

	bool x = true;
	bool y = true;
	bool z = true;
};

class ReorderAxes : public InputModifier
{
public:

	ReorderAxes(Axes axes = Axes::XYZ)
		:
		axes(axes)
	{
	}

	[[nodiscard]] virtual InputActionValue ModifyValue(InputActionValue value, [[maybe_unused]] EActionValueType valueType) const override
	{

		auto vec3 = value.Get<Vector3D>();

		switch (axes)
		{
		case Axes::XYZ:
			return value;
		case Axes::XZY:
			return InputActionValue(vec3.x, vec3.z, vec3.y);
		case Axes::YXZ:
			return InputActionValue(vec3.y, vec3.x, vec3.z);
		case Axes::YZX:
			return InputActionValue(vec3.y, vec3.z, vec3.x);
		case Axes::ZXY:
			return InputActionValue(vec3.z, vec3.x, vec3.y);
		case Axes::ZYX:
			return InputActionValue(vec3.z, vec3.y, vec3.x);
		}

		return value;
	}

public:

	Axes axes = Axes::XYZ;
};

namespace Modifiers
{
	inline std::unique_ptr<InputModifier> Negate(bool x = true, bool y = true, bool z = true)
	{
		return std::make_unique<::Negate>(x, y, z);
	}

	inline std::unique_ptr<InputModifier> ReorderAxes(Axes axes = Axes::XYZ)
	{
		return std::make_unique<::ReorderAxes>(axes);
	}
}