#pragma once
#include "Core.h"
#include "Types.h"
#include <array>
#include <concepts>
#include <format>
#include <functional>
#include <limits>
#include <span>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

#define ACTION_STATE_COUNT static_cast<size_t>(EActionState::COUNT)

enum class EActionState : uint8
{
	Started, // Input is active and the triggers have been satisfied (fires once)
	Triggered, // Input is active and the triggers are satisfied (fires every update, including when "Started" fires)
	Ongoing, // Either the input is not active or the triggers are not yet satisfied (fires every update)
	Completed, // Input and triggers have been satisfied before, but the input is no longer active (fires once)
	Interrupted, // Input and triggers have been satisfied before, the input is still active, but the triggers are no longer satisfied (fires once)
	Canceled, // Input was active before, but is no longer active and the triggers were never satisfied (fires once)

	COUNT,
	Invalid
};

enum class EActionValueType : uint8
{
	Boolean,
	Vector1D,
	Vector2D,
	Vector3D
};

template <typename T>
concept InputActionValueType = std::same_as<T, bool> ||
std::same_as<T, Vector1D> ||
std::same_as<T, Vector2D> ||
std::same_as<T, Vector3D>;

struct InputActionValue
{

public:

	InputActionValue()
		:
		value(0.0f, 0.0f, 0.0f)
	{}

	InputActionValue(bool value)
		:
		value(value, 0.0f, 0.0f)
	{}

	InputActionValue(float value)
		:
		value(value, 0.0f, 0.0f)
	{}

	InputActionValue(float valueX, float valueY)
		:
		value(valueX, valueY, 0.0f)
	{}

	InputActionValue(float valueX, float valueY, float valueZ)
		:
		value(valueX, valueY, valueZ)
	{}

private:

	InputActionValue(Vector3D value)
		:
		value(value)
	{}

public:

	template<InputActionValueType T>
	[[nodiscard]] T Get() const
	{
		if constexpr (std::is_same_v<T, bool>)
		{
			return value.x > 0.0f;
		}
		else if constexpr (std::is_same_v<T, Vector1D>)
		{
			return value.x;
		}
		else if constexpr (std::is_same_v<T, Vector2D>)
		{
			return Vector2D{ value.x, value.y };
		}
		else if constexpr (std::is_same_v<T, Vector3D>)
		{
			return value;
		}
	}

	InputActionValue& operator+=(const InputActionValue& other)
	{
		value += other.value;
		return *this;
	}

	[[nodiscard]] InputActionValue operator+(const InputActionValue& other) const
	{
		return InputActionValue(
			value + other.value
		);
	}

	[[nodiscard]] FORCEINLINE bool IsNonZero() const
	{
		return value.LengthSquared() > std::numeric_limits<float>::epsilon();
	}

protected:

	Vector3D value;
};


class InputAction
{
	using Callback = std::function<void(InputActionValue value, float deltaSeconds)>;

public:

	InputAction(const std::string& name, EActionValueType valueType = EActionValueType::Boolean);

public:

	template <typename Func>
	void BindCallback(EActionState state, Func&& callback);

	void Invoke(EActionState state, InputActionValue value, float deltaSeconds) const;

	[[nodiscard]] FORCEINLINE constexpr EActionValueType GetValueType() const noexcept
	{
		return mValueType;
	}

	[[nodiscard]] FORCEINLINE std::span<const Callback> GetStateCallbacks(EActionState state) const
	{
		return mCallbacks[static_cast<std::size_t>(state)];
	}

	[[nodiscard]] FORCEINLINE constexpr std::string GetName() const
	{
		return mName;
	}

protected:

	std::string mName;

	EActionValueType mValueType;

	std::array<std::vector<Callback>, ACTION_STATE_COUNT> mCallbacks;

};

template <typename Func>
void InputAction::BindCallback(EActionState state, Func&& callback)
{
	static_assert(
		std::is_invocable_v<Func> ||
		std::is_invocable_v<Func, InputActionValue> ||
		std::is_invocable_v<Func, InputActionValue, float>,
		"Parameter callback must be invocable with one of the following signatures: "
		"void(), void(InputActionValue value), void(InputActionValue value, float deltaSeconds)"
	);

	auto index = static_cast<std::size_t>(state);

	if constexpr (std::is_invocable_v<Func, InputActionValue, float>)
	{
		mCallbacks[index].emplace_back(std::forward<Func>(callback));
	}
	else if constexpr (std::is_invocable_v<Func, InputActionValue>)
	{
		mCallbacks[index].emplace_back(
			[callback = std::forward<Func>(callback)](InputActionValue value, float)
			{
				callback(value);
			}
		);
	}
	else if constexpr (std::is_invocable_v<Func>)
	{
		mCallbacks[index].emplace_back(
			[callback = std::forward<Func>(callback)](InputActionValue, float)
			{
				callback();
			}
		);
	}
}