#include "pch.h"
#include "CMyString.h"

CMyString::CIterator::CIterator(CMyString& str, size_t pos, bool isReverse)
	: m_str(str)
	, m_pos(pos)
	, m_isReverse(isReverse)
{
}

char& CMyString::CIterator::operator*() const
{
	return m_str[m_pos];
}

CMyString::CIterator& CMyString::CIterator::operator++()
{
	m_isReverse ? --m_pos : ++m_pos;

	return *this;
}

CMyString::CIterator& CMyString::CIterator::operator--()
{
	m_isReverse ? ++m_pos : --m_pos;

	return *this;
}

CMyString::CIterator const CMyString::CIterator::operator++(int)
{
	auto tmpCopy(*this);
	m_isReverse ? --m_pos : ++m_pos;

	return tmpCopy;
}

CMyString::CIterator const CMyString::CIterator::operator--(int)
{
	auto tmpCopy(*this);
	m_isReverse ? ++m_pos : --m_pos;

	return tmpCopy;
}

CMyString::CIterator const CMyString::CIterator::operator+(int offset) const
{
	return CIterator(m_str, m_pos + offset, m_isReverse);
}

CMyString::CIterator const CMyString::CIterator::operator-(int offset) const
{
	return CIterator(m_str, m_pos - offset, m_isReverse);
}

bool CMyString::CIterator::operator==(const CIterator& other) const
{
	return (m_pos == other.m_pos);
}

bool CMyString::CIterator::operator!=(const CIterator& other) const
{
	return !(*this == other);
}

bool CMyString::CIterator::operator<(const CIterator& other) const
{
	return m_pos < other.m_pos;
}

bool CMyString::CIterator::operator>(const CIterator& other) const
{
	return m_pos > other.m_pos;
}

CMyString::CIterator operator+(int offset, CMyString::CIterator const& it)
{
	return it + offset;
}
