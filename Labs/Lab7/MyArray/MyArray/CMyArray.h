#pragma once

#include "pch.h"

template <typename T>
class CMyArray
{
public:
	template <typename T, bool isReversed>
	class CArrayIterator : public std::iterator<std::input_iterator_tag, T>
	{
	public:
		CArrayIterator()
			: m_isReversed(isReversed)
		{
		}

		CArrayIterator(T* elemPtr)
			: m_isReversed(isReversed)
			, m_elemPtr(elemPtr)
		{
		}

		T& operator*() const
		{
			return *m_elemPtr;
		}

		T* operator->() const
		{
			return m_elemPtr;
		}

		CArrayIterator& operator++()
		{
			isReversed ? --m_elemPtr : ++m_elemPtr;

			return *this;
		}

		CArrayIterator& operator--()
		{
			isReversed ? ++m_elemPtr : --m_elemPtr;

			return *this;
		}

		CArrayIterator const operator++(int)
		{
			CArrayIterator tmpCopy(*this);
			isReversed ? --m_elemPtr : ++m_elemPtr;

			return tmpCopy;
		}

		CArrayIterator const operator--(int)
		{
			CArrayIterator tmpCopy(*this);
			isReversed ? ++m_elemPtr : --m_elemPtr;

			return tmpCopy;
		}

		bool operator==(const CArrayIterator& other) const
		{
			return (m_elemPtr == other.m_elemPtr) && (m_isReversed == other.m_isReversed);
		}

		bool operator!=(const CArrayIterator& other) const
		{
			return !(*this == other);
		}

	private:
		T* m_elemPtr;
		bool m_isReversed;
	};

	typedef CArrayIterator<T, false> iterator;
	typedef CArrayIterator<T, true> reverse_iterator;

	CMyArray() = default;
	CMyArray(const CMyArray& arr);
	CMyArray(CMyArray&& other) noexcept;

	CMyArray& operator=(CMyArray const& other);
	CMyArray& operator=(CMyArray&& other) noexcept;

	const T& operator[](size_t index) const;
	T& operator[](size_t index);

	void Append(const T& value);
	size_t GetSize() const;
	size_t GetCapacity() const;
	void Resize(size_t newSize);
	void Clear();

	iterator begin()
	{
		return iterator(m_begin);
	}

	iterator end()
	{
		return iterator(m_end);
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(m_end - 1);
	}

	reverse_iterator rend()
	{
		return reverse_iterator(m_begin - 1);
	}

	~CMyArray()
	{
		DeleteItems(m_begin, m_end);
	}

private:
	static void DeleteItems(T* begin, T* end);
	static void CopyItems(const T* srcBegin, T* srcEnd, T* const dstBegin, T*& dstEnd);
	static void DestroyItems(T* from, T* to);
	static T* RawAlloc(size_t n);
	static void RawDealloc(T* p);

private:
	T* m_begin = nullptr;
	T* m_end = nullptr;
	T* m_endOfCapacity = nullptr;
};

#include "CMyArray.ipp"
