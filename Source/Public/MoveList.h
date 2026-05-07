#pragma once

#include <vector>

template <typename T>
struct MoveList
{
	template <typename... Ts>
		requires (requires(std::vector<T>& v, Ts&&... xs) {
		(v.push_back(std::forward<Ts>(xs)), ...);
	})
	MoveList(Ts&&... args)
	{
		objects.reserve(sizeof...(args));
		(objects.push_back(std::forward<Ts>(args)), ...);
	}

	auto begin() { return objects.begin(); }
	auto end() { return objects.end(); }

	auto begin() const { return objects.begin(); }
	auto end()   const { return objects.end(); }

	auto cbegin() const { return objects.cbegin(); }
	auto cend()   const { return objects.cend(); }

	
	operator std::vector<T>&() &
	{
		return objects;
	}

	operator std::vector<T>&&() &&
	{
		return std::move(objects);
	}

private:

	std::vector<T> objects;
};