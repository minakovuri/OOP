#pragma once

#include <string>

struct SAthlete
{
	std::string fullName;
	double height;
	double weight;
};

bool IsHeigher(const SAthlete& lhs, const SAthlete& rhs);
bool IsMoreWeight(const SAthlete& lhs, const SAthlete& rhs);