#include "pch.h"

using VectorOfDoubles = std::vector<double>;

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

int main()
{
	VectorOfDoubles numbers(std::istream_iterator<double>(std::cin), (std::istream_iterator<double>()));

	ProcessVector(numbers);

	std::sort(numbers.begin(), numbers.end());

	std::cout << std::fixed;
	std::cout << std::setprecision(3);
	std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<double>(std::cout, " "));
}
