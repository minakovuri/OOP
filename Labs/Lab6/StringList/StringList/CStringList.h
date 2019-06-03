#pragma once
#include "pch.h"

class CStringList
{
	struct Node
	{
		Node(const std::string& data, Node* prev, std::unique_ptr<Node>&& next)
			: data(data)
			, prev(prev)
			, next(std::move(next))
		{
		}

		std::string data;
		Node* prev;
		std::unique_ptr<Node> next;
	};

public:
	class CIterator
	{
		friend CStringList;

	public:
		CIterator() = default;
		CIterator(Node* node);

		std::string& operator*() const;
		Node* operator->() const;

		CIterator& operator++();
		CIterator const operator++(int);

		CIterator& operator--();
		CIterator const operator--(int);

		bool operator==(CIterator const& other) const;
		bool operator!=(CIterator const& other) const;

	private:
		Node* m_node = nullptr;
	};

	CStringList() = default;
	//CStringList(const CStringList& other);
	//CStringList(CStringList&& other);

	void PushFront(const std::string& el);
	void Append(const std::string& data);

	size_t GetSize() const;
	bool IsEmpty() const;

	void Clear();

	void Insert(CIterator const& it, const std::string& el);
	void Erase(CIterator const& it);

	std::string& GetLastElement();
	std::string const& GetLastElement() const;

	CIterator begin();
	CIterator const begin() const;
	CIterator const cbegin() const;

	CIterator end();
	CIterator const end() const;
	CIterator const cend() const;

	~CStringList();

private:
	size_t m_size = 0;
	std::unique_ptr<Node> m_firstNode;
	Node* m_lastNode = nullptr;
};
