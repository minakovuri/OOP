#include "pch.h"
#include "ProcessVector.h"

void ProcessVector(VectorOfDoubles& numbers)
{
	if (!numbers.size())
	{
		return;
	}

	auto maxNumber = *std::max_element(numbers.begin(), numbers.end());
	auto minNumber = *std::min_element(numbers.begin(), numbers.end());

	for (auto& number : numbers)
	{
		if (/*signbit(number)*/number < 0)
		{
			number *= (minNumber * maxNumber);
		}
	}
}
