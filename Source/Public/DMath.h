#pragma once

#include <cmath>
#include <cstdlib>
#include <limits>
#include <string>
#include <type_traits>

namespace DMath
{
#pragma region TVector3D

	template <typename T> requires std::is_arithmetic_v<T>
	class TVector3D
	{
	public:

		constexpr TVector3D()
			:
			x(static_cast<T>(0)),
			y(static_cast<T>(0)),
			z(static_cast<T>(0))
		{}

		constexpr TVector3D(T x, T y, T z)
			:
			x(x),
			y(y),
			z(z)
		{}

	public:

		[[nodiscard]] TVector3D<T> operator+(const TVector3D<T>& other) const
		{
			return TVector3D<T>(x + other.x, y + other.y, z + other.z);
		}

		TVector3D<T>& operator+=(const TVector3D<T>& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}

		[[nodiscard]] TVector3D<T> operator-(const TVector3D<T>& other) const
		{
			return TVector3D<T>(x - other.x, y - other.y, z - other.z);
		}

		TVector3D<T>& operator-=(const TVector3D<T>& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;
		}

		[[nodiscard]] TVector3D<T> operator*(const TVector3D<T>& other) const
		{
			return TVector3D<T>(x * other.x, y * other.y, z * other.z);
		}

		TVector3D<T>& operator*=(const TVector3D<T>& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			return *this;
		}

		[[nodiscard]] TVector3D<T> operator/(const TVector3D<T>& other) const
		{
			return TVector3D<T>(x / other.x, y / other.y, z / other.z);
		}

		TVector3D<T>& operator/=(const TVector3D<T>& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			return *this;
		}

		[[nodiscard]] TVector3D<T> operator*(T scalar) const
		{
			return TVector3D<T>(x * scalar, y * scalar, z * scalar);
		}

		TVector3D<T>& operator*=(T scalar)
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
			return *this;
		}

		[[nodiscard]] TVector3D<T> operator/(T scalar) const
		{
			return TVector3D<T>(x / scalar, y / scalar, z / scalar);
		}

		TVector3D<T>& operator/=(T scalar)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			return *this;
		}

		[[nodiscard]] TVector3D<T> operator-() const
		{
			return TVector3D<T>(-x, -y, -z);
		}

	public:

		[[nodiscard]] bool operator==(const TVector3D<T>& other) const
		{
			return Equals(other);
		}

		[[nodiscard]] bool operator!=(const TVector3D<T>& other) const
		{
			return !Equals(other);
		}

		[[nodiscard]] bool Equals(const TVector3D<T>& other, T tolerance = std::numeric_limits<T>::epsilon()) const
		{
			return std::abs(x - other.x) <= tolerance &&
				std::abs(y - other.y) <= tolerance &&
				std::abs(z - other.z) <= tolerance;
		}

		[[nodiscard]] T Dot(const TVector3D<T>& other) const
		{
			return x * other.x + y * other.y + z * other.z;
		}

		[[nodiscard]] TVector3D<T> Cross(const TVector3D<T>& other) const
		{
			return TVector3D<T>(
				y * other.z - z * other.y,
				z * other.x - x * other.z,
				x * other.y - y * other.x
			);
		}

		[[nodiscard]] T Length() const
		{
			return std::sqrt(x * x + y * y + z * z);
		}

		[[nodiscard]] T LengthSquared() const
		{
			return x * x + y * y + z * z;
		}

		TVector3D<T>& Normalize(T tolerance = std::numeric_limits<T>::epsilon())
		{
			T length = Length();
			if (length > tolerance)
			{
				x /= length;
				y /= length;
				z /= length;
			}
			else
			{
				x = static_cast<T>(0);
				y = static_cast<T>(0);
				z = static_cast<T>(0);
			}
			return *this;
		}

	public:

		[[nodiscard]] static TVector3D<T> Zero()
		{
			return TVector3D<T>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(0));
		}

		[[nodiscard]] static TVector3D<T> One()
		{
			return TVector3D<T>(static_cast<T>(1), static_cast<T>(1), static_cast<T>(1));
		}

		[[nodiscard]] std::string ToString() const
		{
			return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
		}


	public:

		T x;
		T y;
		T z;
	};

#pragma endregion

#pragma region TVector2D

	template <typename T> requires std::is_arithmetic_v<T>
	class TVector2D
	{
	public:

		constexpr TVector2D()
			:
			x(static_cast<T>(0)),
			y(static_cast<T>(0))
		{}

		constexpr TVector2D(T x, T y)
			:
			x(x),
			y(y)
		{}

	public:

		[[nodiscard]] TVector2D<T> operator+(const TVector2D<T>& other) const
		{
			return TVector2D<T>(x + other.x, y + other.y);
		}

		TVector2D<T>& operator+=(const TVector2D<T>& other)
		{
			x += other.x;
			y += other.y;
			return *this;
		}

		[[nodiscard]] TVector2D<T> operator-(const TVector2D<T>& other) const
		{
			return TVector2D<T>(x - other.x, y - other.y);
		}

		TVector2D<T>& operator-=(const TVector2D<T>& other)
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}

		[[nodiscard]] TVector2D<T> operator*(const TVector2D<T>& other) const
		{
			return TVector2D<T>(x * other.x, y * other.y);
		}

		TVector2D<T>& operator*=(const TVector2D<T>& other)
		{
			x *= other.x;
			y *= other.y;
			return *this;
		}

		[[nodiscard]] TVector2D<T> operator/(const TVector2D<T>& other) const
		{
			return TVector2D<T>(x / other.x, y / other.y);
		}

		TVector2D<T>& operator/=(const TVector2D<T>& other)
		{
			x /= other.x;
			y /= other.y;
			return *this;
		}

		[[nodiscard]] TVector2D<T> operator*(T scalar) const
		{
			return TVector2D<T>(x * scalar, y * scalar);
		}

		TVector2D<T>& operator*=(T scalar)
		{
			x *= scalar;
			y *= scalar;
			return *this;
		}

		[[nodiscard]] TVector2D<T> operator/(T scalar) const
		{
			return TVector2D<T>(x / scalar, y / scalar);
		}

		TVector2D<T>& operator/=(T scalar)
		{
			x /= scalar;
			y /= scalar;
			return *this;
		}

		[[nodiscard]] TVector2D<T> operator-() const
		{
			return TVector2D<T>(-x, -y);
		}

	public:

		[[nodiscard]] bool operator==(const TVector2D<T>& other) const
		{
			return Equals(other);
		}

		[[nodiscard]] bool operator!=(const TVector2D<T>& other) const
		{
			return !Equals(other);
		}

		[[nodiscard]] bool Equals(const TVector2D<T>& other, T tolerance = std::numeric_limits<T>::epsilon()) const
		{
			return std::abs(x - other.x) <= tolerance &&
				std::abs(y - other.y) <= tolerance;
		}

		[[nodiscard]] T Dot(const TVector2D<T>& other) const
		{
			return x * other.x + y * other.y;
		}

		// 2D cross product returns scalar (z component of 3D cross)
		[[nodiscard]] T Cross(const TVector2D<T>& other) const
		{
			return x * other.y - y * other.x;
		}

		[[nodiscard]] T Length() const
		{
			return std::sqrt(x * x + y * y);
		}

		[[nodiscard]] T LengthSquared() const
		{
			return x * x + y * y;
		}

		TVector2D<T>& Normalize(T tolerance = std::numeric_limits<T>::epsilon())
		{
			T length = Length();
			if (length > tolerance)
			{
				x /= length;
				y /= length;
			}
			else
			{
				x = static_cast<T>(0);
				y = static_cast<T>(0);
			}
			return *this;
		}

	public:

		[[nodiscard]] static TVector2D<T> Zero()
		{
			return TVector2D<T>(static_cast<T>(0), static_cast<T>(0));
		}

		[[nodiscard]] static TVector2D<T> One()
		{
			return TVector2D<T>(static_cast<T>(1), static_cast<T>(1));
		}

		[[nodiscard]] std::string ToString() const
		{
			return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
		}

	public:
		T x;
		T y;
	};

#pragma endregion

	template<typename T>
	[[nodiscard]] constexpr T Lerp(const T& start, const T& end, float alpha)
	{
		return start + (end - start) * alpha;
	}

	[[nodiscard]] constexpr float ClampSmall(float value, float threshhold)
	{
		return (std::abs(value) < threshhold) ? 0.0f : value;
	}
}

// Hash specializations for unordered_map/unordered_set support
namespace std
{
	template <typename T>
	struct hash<DMath::TVector3D<T>>
	{
		std::size_t operator()(const DMath::TVector3D<T>& vec) const noexcept
		{
			// Combine hashes of all three components
			const std::size_t h1 = std::hash<T>{}(vec.x);
			const std::size_t h2 = std::hash<T>{}(vec.y);
			const std::size_t h3 = std::hash<T>{}(vec.z);

			// Simple hash combination using FNV-like mixing
			return h1 ^ (h2 << 1) ^ (h3 << 2);
		}
	};

	template <typename T>
	struct hash<DMath::TVector2D<T>>
	{
		std::size_t operator()(const DMath::TVector2D<T>& vec) const noexcept
		{
			// Combine hashes of both components
			const std::size_t h1 = std::hash<T>{}(vec.x);
			const std::size_t h2 = std::hash<T>{}(vec.y);

			// Simple hash combination using FNV-like mixing
			return h1 ^ (h2 << 1);
		}
	};
}