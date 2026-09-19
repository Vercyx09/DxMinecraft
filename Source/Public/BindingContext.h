#pragma once
#include "InputAction.h"
#include "InputModifier.h"
#include "InputTrigger.h"
#include "MoveList.h"
#include "Types.h"
#include <algorithm>
#include <memory>
#include <span>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

//class InputAction;
enum class EKey : uint8;
//class InputModifier;
//class InputTrigger;

using ActionHandle = std::size_t;

enum class EKey : uint8
{
	// Keyboard letters
	A, B, C, D, E, F, G, H, I, J, K, L, M,
	N, O, P, Q, R, S, T, U, V, W, X, Y, Z,

	// Numbers (top row)
	Num0, Num1, Num2, Num3, Num4,
	Num5, Num6, Num7, Num8, Num9,

	// Function keys
	F1, F2, F3, F4, F5, F6,
	F7, F8, F9, F10, F11, F12,

	// Arrow keys
	ArrowUp,
	ArrowDown,
	ArrowLeft,
	ArrowRight,

	// Control keys
	Escape,
	Tab,
	CapsLock,
	LeftShift,
	RightShift,
	LeftCtrl,
	RightCtrl,
	LeftAlt,
	RightAlt,
	Space,
	Enter,
	Backspace,

	// Symbols
	Minus,
	Equal,
	LeftBracket,
	RightBracket,
	Backslash,
	Semicolon,
	Apostrophe,
	Comma,
	Period,
	Slash,

	// Numpad
	Numpad0, Numpad1, Numpad2, Numpad3, Numpad4,
	Numpad5, Numpad6, Numpad7, Numpad8, Numpad9,
	NumpadAdd, NumpadSubtract, NumpadMultiply, NumpadDivide,
	NumpadEnter, NumpadDecimal,

	// Mouse
	MouseLeft,
	MouseRight,
	MouseMiddle,
	MouseButton1,
	MouseButton2,
	MouseX,
	MouseY,
	MouseWheelUp,
	MouseWheelDown,

	// Other
	PrintScreen,
	ScrollLock,
	PauseBreak,
	Insert,
	Delete,
	Home,
	End,
	PageUp,
	PageDown,
	LeftWindows,
	RightWindows,

	// Special marker
	Unknown,
	COUNT
};


[[nodiscard]] std::string ToString(EKey key);

struct Mapping
{
	Mapping(EKey key, MoveList<std::unique_ptr<const InputModifier>>&& modifiers, MoveList<std::unique_ptr<InputTrigger>>&& triggers)
		:
		key(key),
		modifiers(std::move(modifiers)),
		triggers(std::move(triggers))
	{}

	EKey key;
	std::vector<std::unique_ptr<const InputModifier>> modifiers;
	std::vector<std::unique_ptr<InputTrigger>> triggers;
};

struct ActionMapping
{
	ActionMapping(const std::shared_ptr<InputAction>& action, MoveList<Mapping>&& mappings)
		:
		action(action),
		mappings(std::move(mappings))
	{}

	std::shared_ptr<InputAction> action;
	std::vector<Mapping> mappings;
};

template <typename T>
concept RValueActionMappingType =
std::is_same_v<std::remove_cvref_t<T>, ActionMapping>&&
std::is_rvalue_reference_v<T&&>;

class BindingContext
{
public:

	struct Binding
	{
		ActionHandle actionHandle;
		std::vector<std::unique_ptr<const InputModifier>> modifiers;
		std::vector<std::unique_ptr<InputTrigger>> triggers;
		EKey key;

		Binding(
			ActionHandle actionHandle,
			std::vector<std::unique_ptr<const InputModifier>>&& modifiers,
			std::vector<std::unique_ptr<InputTrigger>>&& triggers,
			EKey key
		)
			:
			actionHandle(actionHandle),
			modifiers(std::move(modifiers)),
			triggers(std::move(triggers)),
			key(key)
		{}

		Binding(const Binding& other) = delete;

		Binding& operator=(const Binding& other) = delete;

		Binding(Binding&& other) noexcept = default;

		Binding& operator=(Binding&& other) noexcept = default;
	};

public:

	BindingContext() = default;

	template <RValueActionMappingType... Args>
	explicit BindingContext(Args&&... mappings);

	~BindingContext() = default;

	BindingContext(const BindingContext&) = delete;

	BindingContext& operator=(const BindingContext&) = delete;

	BindingContext(BindingContext&&) = delete;

	BindingContext& operator=(BindingContext&&) = delete;

public:

	std::span<const Binding> GetBindingsForKey(EKey key) const;

	const InputAction* GetAction(ActionHandle handle) const;

	void AddActionMapping(ActionMapping&& actionMapping);

private:

	std::unordered_map<EKey, std::vector<Binding>> mKeyActionsMap;

	std::vector<std::shared_ptr<const InputAction>> mActions;
};

template<RValueActionMappingType... Args>
inline BindingContext::BindingContext(Args&&... mappings)
{
	(AddActionMapping(std::move(mappings)), ...);
}
