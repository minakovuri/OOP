#pragma once

class CMyString
{
public:
	class CIterator
	{
	public:
		CIterator(CMyString& str, size_t pos, bool isReverse);

		char& operator*() const;

		CIterator& operator++();
		CIterator& operator--();

		CIterator const operator++(int);
		CIterator const operator--(int);

		CIterator const operator+(int offset) const;
		CIterator const operator-(int offset) const;

		bool operator==(const CIterator& other) const;
		bool operator!=(const CIterator& other) const;
		bool operator<(const CIterator& other) const;
		bool operator>(const CIterator& other) const;

	private:
		CMyString& m_str;
		size_t m_pos;
		bool m_isReverse;
	};

	CMyString() = default;

	CMyString(const char* pString);
	CMyString(const char* pString, size_t length);

	CMyString(CMyString const& other);
	CMyString(CMyString&& other);
	CMyString(std::string const& stlString);

	size_t GetLength() const;
	const char* GetStringData() const;

	CMyString SubString(size_t start, size_t length = SIZE_MAX) const;
	void Clear();

	CMyString& operator=(const CMyString& other);
	CMyString& operator=(CMyString&& other);

	CMyString const operator+(CMyString const& other) const;
	CMyString const operator+(std::string const& other) const;
	CMyString const operator+(const char* other) const;

	CMyString& operator+=(CMyString const& other);

	bool operator==(CMyString const& other) const;
	bool operator!=(CMyString const& other) const;

	bool operator>(const CMyString& other) const;
	bool operator<(const CMyString& other) const;
	bool operator>=(const CMyString& other) const;
	bool operator<=(const CMyString& other) const;

	const char& operator[](size_t index) const;
	char& operator[](size_t index);

	CIterator begin();
	CIterator end();

	~CMyString();

private:
	/*enum class ComparedValue
	{
		Less,
		Equal,
		More,
	};*/

	void AllocateMemory(size_t size);
	void DeallocateMemory();

	//ComparedValue Compare(const CMyString& other) const;

private:
	char* m_pChars = nullptr;
	size_t m_length = 0;
};

std::ostream& operator<<(std::ostream& os, const CMyString& str);
std::istream& operator>>(std::istream& is, CMyString& str);

CMyString::CIterator operator+(int offset, CMyString::CIterator const& it);
