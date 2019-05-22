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
	//typedef CArrayIterator<const T, false> const_iterator;
	typedef CArrayIterator<T, true> reverse_iterator;
	//typedef CArrayIterator<const T, true> const_reverse_iterator;

	CMyArray() = default;

	// конструктор копирования
	CMyArray(const CMyArray& arr)
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

	// конструктор перемещения
	CMyArray(CMyArray&& other)
		: m_begin(other.m_begin)
		, m_end(other.m_end)
		, m_endOfCapacity(other.m_endOfCapacity)
	{
		other.m_begin = nullptr;
		other.m_end = nullptr;
		other.m_endOfCapacity = nullptr;
	}

	// оператор присваивания
	CMyArray& operator=(CMyArray const& other)
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

	// перемещающий оператор присваивания
	CMyArray& operator=(CMyArray && other)
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

	void Append(const T& value)
	{
		if (m_end == m_endOfCapacity) // no free space
		{
			size_t newCapacity = std::max(size_t(1), GetCapacity() * 2);

			auto newBegin = RawAlloc(newCapacity);
			T* newEnd = newBegin;

			try
			{
				CopyItems(m_begin, m_end, newBegin, newEnd);
				// Конструируем копию value по адресу newItemLocation
				new (newEnd) T(value);
				++newEnd;
			}
			catch (const std::exception& e)
			{
				DeleteItems(newBegin, newEnd);
				throw e;
			}

			DeleteItems(m_begin, m_end);

			// Переключаемся на использование нового хранилища элементов
			m_begin = newBegin;
			m_end = newEnd;
			m_endOfCapacity = m_begin + newCapacity;
		}
		else // has free space
		{
			new (m_end) T(value);
			++m_end;
		}
	}

	size_t GetSize() const
	{
		return m_end - m_begin;
	}

	size_t GetCapacity() const
	{
		return m_endOfCapacity - m_begin;
	}

	// оператор индексированного доступа для чтения
	const T& operator[](size_t index) const
	{
		if (index >= GetSize())
			throw std::out_of_range("requested index is out of range");

		return *(m_begin + index);
	}

	// оператор индексированного доступа для записи
	T& operator[](size_t index)
	{
		if (index >= GetSize())
			throw std::out_of_range("requested index is out of range");

		return *(m_begin + index);
	}

	void Resize(size_t newSize)
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

	void Clear()
	{
		DeleteItems(m_begin, m_end);

		m_begin = nullptr;
		m_end = nullptr;
		m_endOfCapacity = nullptr;
	}

	iterator begin()
	{
		return iterator(m_begin);
	}
	
	/*const_iterator cbegin() const
	{
		return const_iterator(m_begin);
	}*/

	iterator end()
	{
		return iterator(m_end);
	}

	/*const_iterator cend() const
	{
		return const_iterator(m_end);
	}*/

	reverse_iterator rbegin()
	{
		return reverse_iterator(m_end - 1);
	}

	/*const_reverse_iterator rcbegin() const
	{
		return const_reverse_iterator(m_end - 1);
	}*/

	reverse_iterator rend()
	{
		return reverse_iterator(m_begin - 1);
	}

	/*const_reverse_iterator rcend() const
	{
		return const_reverse_iterator(m_begin - 1);
	}*/

	~CMyArray()
	{
		DeleteItems(m_begin, m_end);
	}

private:
	static void DeleteItems(T* begin, T* end)
	{
		// Разрушаем старые элементы
		DestroyItems(begin, end);
		// Освобождаем область памяти для их хранения
		RawDealloc(begin);
	}

	// Копирует элементы из текущего вектора в to, возвращает newEnd
	static void CopyItems(const T* srcBegin, T* srcEnd, T* const dstBegin, T*& dstEnd)
	{
		for (dstEnd = dstBegin; srcBegin != srcEnd; ++srcBegin, ++dstEnd)
		{
			// Construct "T" at "dstEnd" as a copy of "*begin"
			new (dstEnd) T(*srcBegin);
		}
	}

	static void DestroyItems(T* from, T* to)
	{
		// dst - адрес объект, при конструирование которого было выброшено исключение
		// to - первый скорнструированный объект
		while (to != from)
		{
			--to;
			// явно вызываем деструктор для шаблонного типа T
			to->~T();
		}
	}

	static T* RawAlloc(size_t n)
	{
		size_t memSize = n * sizeof(T);
		T* p = static_cast<T*>(malloc(memSize));

		if (!p)
		{
			throw std::bad_alloc();
		}
		return p;
	}

	static void RawDealloc(T* p)
	{
		free(p);
	}

private:
	T* m_begin = nullptr;
	T* m_end = nullptr;
	T* m_endOfCapacity = nullptr;
};
