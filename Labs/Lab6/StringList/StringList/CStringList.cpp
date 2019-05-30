#include "pch.h"
#include "CStringList.h"

size_t CStringList::GetSize() const
{
	return m_size;
}

bool CStringList::IsEmpty() const
{
	return (m_size == 0u);
}

void CStringList::Append(const std::string& el)
{
	auto newNode = std::make_unique<Node>(el, m_lastNode, nullptr);
	Node* newLastNode = newNode.get();

	if (m_lastNode)
	{
		m_lastNode->next = std::move(newNode);
	}
	else // empty list
	{
		m_firstNode = std::move(newNode);
	}

	m_lastNode = newLastNode;
	++m_size;
}

void CStringList::PushFront(const std::string& el)
{
	auto newNode = std::make_unique<Node>(el, nullptr, std::move(m_firstNode));

	if (m_lastNode)
	{
		newNode->next->prev = newNode.get();
	}
	else // empty list
	{
		m_lastNode = newNode.get();
	}

	m_firstNode = std::move(newNode);
	++m_size;
}

void CStringList::Clear()
{
	m_firstNode = nullptr;
	m_lastNode = nullptr;
	m_size = 0;
}

/*void CStringList::Insert(CIterator const& it, const std::string& el)
{
	if (it == begin() || it == cbegin())
	{
		PushFront(el);
	}
	else if (it == end() || it == cend())
	{
		Append(el);
	}
	else
	{
		auto newNode = std::make_unique<Node>(el, it->prev, std::move(it->prev->next));

		it->prev = std::move(newNode.get());
		it->prev->next = std::move(newNode);
		++m_size;
	}
}*/

/*void CStringList::Erase(CIterator const& it)
{

}*/

std::string& CStringList::GetLastElement()
{
	assert(m_lastNode);
	return m_lastNode->data;
}

std::string const& CStringList::GetLastElement() const
{
	assert(m_lastNode);
	return m_lastNode->data;
}

CStringList::CIterator const CStringList::begin()
{
	return CIterator(m_firstNode.get());
}

CStringList::CIterator const CStringList::cbegin() const
{
	return CIterator(m_firstNode.get());
}

CStringList::CIterator const CStringList::end()
{
	return (m_size == 0u) ? begin() : CIterator(m_lastNode);
}

CStringList::CIterator const CStringList::cend() const
{
	return (m_size == 0u) ? cbegin() : CIterator(m_lastNode);
}

CStringList::~CStringList()
{
}
