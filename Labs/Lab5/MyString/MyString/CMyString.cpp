#include "pch.h"
#include "CMyString.h"

CMyString::CMyString(const char* pString)
	: CMyString(pString, strlen(pString))
{
}

CMyString::CMyString(const char* pString, size_t length)
{
	AllocateMemory(length);
	std::memcpy(m_pChars, pString, length);
}

CMyString::CMyString(CMyString const& other)
	: CMyString(other.m_pChars, other.m_length)
{
}

CMyString::CMyString(std::string const& stlString)
	: CMyString(stlString.c_str(), stlString.length())
{
}

size_t CMyString::GetLength() const
{
	return m_length;
}

const char* CMyString::GetStringData() const
{
	return m_pChars ? m_pChars : "\0";
}

CMyString CMyString::SubString(size_t start, size_t length) const
{
	if (start > m_length - 1)
	{
		throw std::out_of_range("start index is out of range");
	}

	length = std::min(length, m_length - start);

	return CMyString(m_pChars + start, length);
}

void CMyString::Clear()
{
	AllocateMemory(0);
}

CMyString& CMyString::operator=(const CMyString& other)
{
	if (&other != this)
	{
		size_t length = other.GetLength();
		const char* pChars = other.GetStringData();

		AllocateMemory(length);
		std::memcpy(m_pChars, pChars, length);
	}

	return *this;
}

CMyString const CMyString::operator+(CMyString const& other) const
{
	size_t len = m_length + other.m_length;
	char* newStr = new char[len + 1];

	memcpy(newStr, GetStringData(), m_length);
	memcpy(newStr + m_length, other.GetStringData(), other.m_length);

	return CMyString(newStr, len);
}

CMyString const CMyString::operator+(std::string const& other) const
{
	size_t len = m_length + other.length();
	char* newStr = new char[len + 1];

	memcpy(newStr, GetStringData(), m_length);
	memcpy(newStr + m_length, other.c_str(), other.length());

	return CMyString(newStr, len);
}

CMyString const CMyString::operator+(const char* other) const
{
	size_t len = m_length + strlen(other);
	char* newStr = new char[len + 1];

	memcpy(newStr, GetStringData(), m_length);
	memcpy(newStr + m_length, other, strlen(other));

	return CMyString(newStr, len);
}

CMyString& CMyString::operator+=(CMyString const& other)
{
	*this = *this + other;

	return *this;
}

bool CMyString::operator==(CMyString const& other) const
{
	if (m_length != other.m_length)
	{
		return false;
	}

	for (size_t i = 0; i < m_length; i++)
	{
		if (m_pChars[i] != other.m_pChars[i])
		{
			return false;
		}
	}

	return true;
}

bool CMyString::operator!=(CMyString const& other) const
{
	return !(*this == other);
}

const char& CMyString::operator[](size_t index) const
{
	if (index >= m_length)
	{
		throw std::out_of_range("requested index is out of range");
	}

	return m_pChars[index];
}

char& CMyString::operator[](size_t index)
{
	if (index >= m_length)
	{
		throw std::out_of_range("requested index is out of range");
	}

	return m_pChars[index];
}

void CMyString::AllocateMemory(size_t size)
{
	DeallocateMemory();

	m_pChars = new char[size + 1];
	m_pChars[size] = '\0';

	m_length = size;
}

void CMyString::DeallocateMemory()
{
	delete[] m_pChars;
}

CMyString::~CMyString()
{
	DeallocateMemory();
}
