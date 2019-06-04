#pragma once

class CMyString
{
public:
	CMyString() = default;

	CMyString(const char* pString);
	CMyString(const char* pString, size_t length);

	CMyString(CMyString const& other);
	CMyString(std::string const& stlString);

	size_t GetLength() const;
	const char* GetStringData() const;

	CMyString SubString(size_t start, size_t length = SIZE_MAX) const;
	void Clear();

	CMyString& operator=(const CMyString& other);

	CMyString const operator+(CMyString const& other) const;
	CMyString const operator+(std::string const& other) const;
	CMyString const operator+(const char* other) const;

	CMyString& operator+=(CMyString const& other);

	bool operator==(CMyString const& other) const;
	bool operator!=(CMyString const& other) const;

	const char& operator[](size_t index) const;
	char& operator[](size_t index);

	~CMyString();

private:
	void AllocateMemory(size_t size);
	void DeallocateMemory();

private:
	char* m_pChars = nullptr;
	size_t m_length = 0;
};
