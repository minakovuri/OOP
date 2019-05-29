#include "pch.h"
#include "CStringList.h"

CStringList::CIterator::CIterator(Node* node)
	: m_node(node)
{
}

std::string& CStringList::CIterator::operator*() const
{
	return m_node->data;
}

CStringList::Node* CStringList::CIterator::operator->() const
{
	return m_node;
}

CStringList::CIterator& CStringList::CIterator::operator++()
{
	m_node = m_node->next.get();
	return *this;
}

CStringList::CIterator const CStringList::CIterator::operator++(int)
{
	CStringList::CIterator tmpCopy(*this);
	++*this;
	return tmpCopy;
}

CStringList::CIterator& CStringList::CIterator::operator--()
{
	m_node = m_node->prev;
	return *this;
}

CStringList::CIterator const CStringList::CIterator::operator--(int)
{
	CStringList::CIterator tmpCopy(*this);
	--*this;
	return tmpCopy;
}

bool CStringList::CIterator::operator==(CIterator const& other) const
{
	return (m_node == other.m_node);
}

bool CStringList::CIterator::operator!=(CIterator const& other) const
{
	return !(*this == other);
}