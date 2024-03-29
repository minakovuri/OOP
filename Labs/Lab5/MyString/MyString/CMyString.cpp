#include "pch.h"
#include "CMyString.h"

enum class ComparedValue
{
	Less,
	Equal,
	More,
};

ComparedValue Compare(const CMyString& a, const CMyString& b)
{
	const size_t aLen = a.GetLength();
	const size_t bLen = b.GetLength();

	if (aLen < bLen)
	{
		return ComparedValue::More;
	}

	if (aLen > bLen)
	{
		return ComparedValue::Less;
	}

	const auto aStr = a.GetStringData();
	const auto bStr = b.GetStringData();

	for (size_t i = 0; i < aLen; i++)
	{
		if (bStr[i] > aStr[i])
		{
			return ComparedValue::More;
		}

		if (bStr[i] < aStr[i])
		{
			return ComparedValue::Less;
		}
	}

	return ComparedValue::Equal;
}

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

CMyString::CMyString(CMyString&& other)
	: m_pChars(other.m_pChars)
	, m_length(other.m_length)
{
	other.m_pChars = nullptr;
	other.m_length = 0;
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

CMyString& CMyString::operator=(CMyString&& other)
{
	if (&other != this)
	{
		delete[] m_pChars;

		m_pChars = other.m_pChars;
		m_length = other.m_length;

		other.m_pChars = nullptr;
		other.m_length = 0;
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
	return Compare(other, *this) == ComparedValue::Equal;
}

bool CMyString::operator!=(CMyString const& other) const
{
	return !(*this == other);
}

bool CMyString::operator>(const CMyString& other) const
{
	return (Compare(other, *this) == ComparedValue::More);
}

bool CMyString::operator<(const CMyString& other) const
{
	return (Compare(other, *this) == ComparedValue::Less);
}

bool CMyString::operator>=(const CMyString& other) const
{
	const auto comparedValue = Compare(other, *this);

	return (comparedValue == ComparedValue::More) || (comparedValue == ComparedValue::Equal);
}

bool CMyString::operator<=(const CMyString& other) const
{
	const auto comparedValue = Compare(other, *this);

	return (comparedValue == ComparedValue::Less) || (comparedValue == ComparedValue::Equal);
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

/*CMyString::ComparedValue CMyString::Compare(const CMyString& other) const
{
	const size_t otherLen = other.m_length;

	if (otherLen < m_length)
	{
		return CMyString::ComparedValue::More;
	}

	if (otherLen > m_length)
	{
		return CMyString::ComparedValue::Less;
	}

	const auto otherStr = other.GetStringData();
	const auto thisStr = GetStringData();

	for (size_t i = 0; i < m_length; i++)
	{
		if (otherStr[i] > thisStr[i])
		{
			return CMyString::ComparedValue::Less;
		}

		if (otherStr[i] < thisStr[i])
		{
			return CMyString::ComparedValue::More;
		}
	}

	return CMyString::ComparedValue::Equal;
}*/

CMyString::~CMyString()
{
	DeallocateMemory();
}

std::ostream& operator<<(std::ostream& os, const CMyString& str)
{
	os.write(str.GetStringData(), str.GetLength());
	return os;
}

std::istream& operator>>(std::istream& is, CMyString& str)
{
	std::string buff;

	is >> buff;

	str = CMyString(buff);

	return is;
}

CMyString::CIterator CMyString::begin()
{
	return CIterator(*this, 0, false);
}

CMyString::CIterator CMyString::end()
{
	return CIterator(*this, m_length, false);
}
