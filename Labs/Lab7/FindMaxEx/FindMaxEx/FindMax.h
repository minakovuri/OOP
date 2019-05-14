#pragma once

#include <vector>
#include <functional>

template <typename T, typename Less = std::less<>>
bool FindMax(std::vector<T> const& arr, T& maxValue, Less const& less = Less())
{
	if (arr.empty())
	{
		return false;
	}

	T max = arr[0];

	for (const T &element : arr)
	{
		if (less(max, element))
		{
			max = element;
		}
	}

	maxValue = max;

	return true;
}