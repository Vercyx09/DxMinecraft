#pragma once

#ifndef FORCEINLINE
	#if defined(_MSC_VER)
		#define FORCEINLINE __forceinline
	#elif defined(__clang__) || defined(__GNUC__)
		#define FORCEINLINE inline __attribute__((always_inline))
	#else
		#define FORCEINLINE inline
	#endif
#endif