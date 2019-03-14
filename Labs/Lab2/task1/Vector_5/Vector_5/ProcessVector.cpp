#include "ProcessVector.h"
#include "pch.h"

void ProcessVector(VectorOfDoubles& numbers)
{
	auto maxNumber = *std::max_element(numbers.begin(), numbers.end());
	auto minNumber = *std::min_element(numbers.begin(), numbers.end());

	for (auto& number : numbers)
	{
		if (signbit(number))
		{
			number *= (minNumber * maxNumber);
		}
	}
}