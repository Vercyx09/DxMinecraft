#pragma once

#include "DMath.h"
#include <cstdint>

using int8 = std::int8_t;
using uint8 = std::uint8_t;
using int16 = std::int16_t;
using uint16 = std::uint16_t;
using int32 = std::int32_t;
using uint32 = std::uint32_t;
using int64 = std::int64_t;
using uint64 = std::uint64_t;

using Vector1D = float;
using Vector2D = DMath::TVector2D<float>;
using Vector3D = DMath::TVector3D<float>;

union Color
{
	struct
	{
		uint8 R;
		uint8 G;
		uint8 B;
		uint8 A;
	} Components;
	uint32 RGBA;
};