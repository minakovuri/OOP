#include "CMyArray.h"

template <typename T>
CMyArray<T>::CMyArray(const CMyArray& arr)
{
	const auto size = arr.GetSize();
	if (size != 0)
	{
		m_begin = RawAlloc(size);
		try
		{
			CopyItems(arr.m_begin, arr.m_end, m_begin, m_end);
			m_endOfCapacity = m_end;
		}
		catch (const std::exception& e)
		{
			DeleteItems(m_begin, m_end);
			throw e;
		}
	}
}

template <typename T>
CMyArray<T>::CMyArray(CMyArray&& other)
	: m_begin(other.m_begin)
	, m_end(other.m_end)
	, m_endOfCapacity(other.m_endOfCapacity)
{
	other.m_begin = nullptr;
	other.m_end = nullptr;
	other.m_endOfCapacity = nullptr;
}

template <typename T>
CMyArray<T>& CMyArray<T>::operator=(CMyArray const& other)
{
	if (std::addressof(other) != this)
	{
		CMyArray tmpCopy(other);

		std::swap(m_begin, tmpCopy.m_begin);
		std::swap(m_end, tmpCopy.m_end);
		std::swap(m_endOfCapacity, tmpCopy.m_endOfCapacity);
	}

	return *this;
}

template <typename T>
CMyArray<T>& CMyArray<T>::operator=(CMyArray&& other)
{
	if (&other != this)
	{
		DeleteItems(m_begin, m_end);

		m_begin = other.m_begin;
		m_end = other.m_end;
		m_endOfCapacity = other.m_endOfCapacity;

		other.m_begin = nullptr;
		other.m_end = nullptr;
		other.m_endOfCapacity = nullptr;
	}

	return *this;
}

template <typename T>
void CMyArray<T>::Append(const T& value)
{
	if (m_end == m_endOfCapacity)
	{
		size_t newCapacity = std::max(size_t(1), GetCapacity() * 2);

		auto newBegin = RawAlloc(newCapacity);
		T* newEnd = newBegin;

		try
		{
			CopyItems(m_begin, m_end, newBegin, newEnd);
			new (newEnd) T(value);
			++newEnd;
		}
		catch (const std::exception& e)
		{
			DeleteItems(newBegin, newEnd);
			throw e;
		}

		DeleteItems(m_begin, m_end);

		m_begin = newBegin;
		m_end = newEnd;
		m_endOfCapacity = m_begin + newCapacity;
	}
	else
	{
		new (m_end) T(value);
		++m_end;
	}
}

template <typename T>
size_t CMyArray<T>::GetSize() const
{
	return m_end - m_begin;
}

template <typename T>
size_t CMyArray<T>::GetCapacity() const
{
	return m_endOfCapacity - m_begin;
}

template <typename T>
const T& CMyArray<T>::operator[](size_t index) const
{
	if (index >= GetSize())
		throw std::out_of_range("requested index is out of range");

	return *(m_begin + index);
}

template <typename T>
T& CMyArray<T>::operator[](size_t index)
{
	if (index >= GetSize())
		throw std::out_of_range("requested index is out of range");

	return *(m_begin + index);
}

template <typename T>
void CMyArray<T>::Resize(size_t newSize)
{
	size_t oldSize = GetSize();

	if (newSize < oldSize)
	{
		DestroyItems(m_begin + newSize, m_end);
		m_end = m_begin + newSize;
	}
	else
	{
		for (size_t currSize = oldSize; currSize < newSize; currSize++)
		{
			try
			{
				Append(T());
			}
			catch (const std::exception& e)
			{
				throw e;
			}
		}
	}
}

template <typename T>
void CMyArray<T>::Clear()
{
	DeleteItems(m_begin, m_end);

	m_begin = nullptr;
	m_end = nullptr;
	m_endOfCapacity = nullptr;
}

template <typename T>
void CMyArray<T>::DeleteItems(T* begin, T* end)
{
	DestroyItems(begin, end);
	RawDealloc(begin);
}

template <typename T>
void CMyArray<T>::CopyItems(const T* srcBegin, T* srcEnd, T* const dstBegin, T*& dstEnd)
{
	for (dstEnd = dstBegin; srcBegin != srcEnd; ++srcBegin, ++dstEnd)
	{
		new (dstEnd) T(*srcBegin);
	}
}

template <typename T>
void CMyArray<T>::DestroyItems(T* from, T* to)
{
	while (to != from)
	{
		--to;
		to->~T();
	}
}

template <typename T>
T* CMyArray<T>::RawAlloc(size_t n)
{
	size_t memSize = n * sizeof(T);
	T* p = static_cast<T*>(malloc(memSize));

	if (!p)
	{
		throw std::bad_alloc();
	}
	return p;
}

template <typename T>
void CMyArray<T>::RawDealloc(T* p)
{
	free(p);
}