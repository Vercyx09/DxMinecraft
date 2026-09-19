#pragma once
#include <concepts>
#include <format>
#include <string>
#include <string_view>
#include <windows.h>


template <typename T>
concept HasToStringFunction = requires(T t) {
	{ t.ToString() } -> std::convertible_to<std::string>;
};

template <typename T>
concept ToStringFunctionExists = requires(T t) {
	{ ToString(t) } -> std::convertible_to<std::string>;
};

template <typename T>
	requires HasToStringFunction<T>
struct std::formatter<T>
{
	constexpr auto parse(std::format_parse_context& ctx) {
		return ctx.begin();
	}

	auto format(const T& value, std::format_context& ctx) const
	{
		return std::format_to(ctx.out(), "{}", value.ToString());
	}
};

template <typename T>
	requires ToStringFunctionExists<T>
struct std::formatter<T>
{
	constexpr auto parse(std::format_parse_context& ctx) {
		return ctx.begin();
	}

	auto format(const T& value, std::format_context& ctx) const
	{
		return std::format_to(ctx.out(), "{}", ToString(value));
	}
};


class DLog
{
public:

	DLog() = default;

	DLog(const DLog&) = delete;

	DLog& operator=(const DLog&) = delete;

	DLog(DLog&&) = delete;

	DLog& operator=(DLog&&) = delete;

	static void Init();

	static void Shutdown();

public:

	static void Log(std::string_view message);

	static void Warn(std::string_view message);

	static void Error(std::string_view message);

	// Wide string versions
	static void Log(std::wstring_view message);

	static void Warn(std::wstring_view message);

	static void Error(std::wstring_view message);

public:

	template <typename... Args>
	static void Log(std::string_view fmt, Args&&... args)
	{
		const std::string msg = std::vformat(fmt, std::make_format_args(args...));
		Log(msg);
	}

	template <typename... Args>
	static void Warn(std::string_view fmt, Args&&... args)
	{
		const std::string msg = std::vformat(fmt, std::make_format_args(args...));
		Warn(msg);
	}

	template <typename... Args>
	static void Error(std::string_view fmt, Args&&... args)
	{
		const std::string msg = std::vformat(fmt, std::make_format_args(args...));
		Error(msg);
	}


	// Wide string versions
	template <typename... Args>
	static void Log(std::wstring_view fmt, Args&&... args)
	{
		const std::wstring msg = std::vformat(fmt, std::make_wformat_args(args...));
		Log(msg);
	}

	template <typename... Args>
	static void Warn(std::wstring_view fmt, Args&&... args)
	{
		const std::wstring msg = std::vformat(fmt, std::make_wformat_args(args...));
		Warn(msg);
	}

	template <typename... Args>
	static void Error(std::wstring_view fmt, Args&&... args)
	{
		const std::wstring msg = std::vformat(fmt, std::make_wformat_args(args...));
		Error(msg);
	}

private:

	inline static HANDLE sHndConsole = nullptr;
};