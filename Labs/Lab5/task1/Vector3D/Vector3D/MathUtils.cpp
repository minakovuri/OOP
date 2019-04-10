#include "pch.h"
#include "MathUtils.h"
#include <float.h>

bool IsEqual(const double a, const double b)
{
	return std::abs(a - b) < FLT_EPSILON;
}