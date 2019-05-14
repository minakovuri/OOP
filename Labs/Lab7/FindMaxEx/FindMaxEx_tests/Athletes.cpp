#include "pch.h"
#include "Athletes.h"

bool IsHeigher(const SAthlete& lhs, const SAthlete& rhs)
{
	return (lhs.height < rhs.height);
}

bool IsMoreWeight(const SAthlete& lhs, const SAthlete& rhs)
{
	return (lhs.weight < rhs.weight);
}