#pragma once
#include <cmath>

const float floatEpsilon = 0.001;
const float PI = 3.1415926535;

static inline bool floatEqual(float a, float b)
{
	return fabsf(a - b) <= floatEpsilon;
}

static inline float degrees2radians(float degrees)
{
	return PI * degrees / 180.0f;
}

static inline float radians2degrees(float radians)
{
	return 180.0f * radians / PI;
}