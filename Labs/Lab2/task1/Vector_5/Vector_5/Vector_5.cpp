#include "pch.h"
#include <iostream>
#include <iomanip>
#include "ProcessVector.h"

int main()
{
	VectorOfDoubles numbers(std::istream_iterator<double>(std::cin), (std::istream_iterator<double>()));

	ProcessVector(numbers);

	std::sort(numbers.begin(), numbers.end());

	std::cout << std::fixed;
	std::cout << std::setprecision(3);
	std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<double>(std::cout, " "));
}
