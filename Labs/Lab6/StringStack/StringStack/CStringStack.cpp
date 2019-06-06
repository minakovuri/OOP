#include "pch.h"
#include "CStringStack.h"

CStringStack::CStringStack(CStringStack const& other)
{
	CopyElements(other);
}

CStringStack::CStringStack(CStringStack&& other)
	: m_top(other.m_top)
	, m_size(other.m_size)
{
	other.m_top = nullptr;
	other.m_size = 0;
}

void CStringStack::Push(std::string const& str)
{
	auto newNode = std::make_shared<Node>(str, m_top);

	m_top = newNode;
	++m_size;
}

void CStringStack::Pop()
{
	if (IsEmpty())
	{
		throw std::logic_error("Imposible to pop element from empty stack");
	}
	else
	{
		m_top->data.clear();
		m_top = m_top->next;
		--m_size;
	}
}

void CStringStack::Clear() noexcept
{
	while (!IsEmpty())
	{
		m_top->data.clear();
		m_top = m_top->next;
		--m_size;
	}
}

const std::string& CStringStack::GetTop() const
{
	if (IsEmpty())
	{
		throw std::logic_error("Imposible to return content from empty stack");
	}

	return m_top->data;
}

size_t CStringStack::GetSize() const
{
	return m_size;
}

bool CStringStack::IsEmpty() const
{
	return (m_size == 0);
}

CStringStack& CStringStack::operator=(CStringStack const& other)
{
	if (this != &other)
	{
		Clear();
		CopyElements(other);
	}

	return *this;
}

CStringStack& CStringStack::operator=(CStringStack&& other)
{
	if (this != &other)
	{
		m_top = other.m_top;
		m_size = other.m_size;

		other.m_top = nullptr;
		other.m_size = 0;
	}

	return *this;
}

void CStringStack::CopyElements(CStringStack const& copiedStack)
{
	if (!copiedStack.IsEmpty())
	{
		m_top = std::make_shared<Node>(*copiedStack.m_top);

		std::shared_ptr<Node> pCopiedNode = copiedStack.m_top;
		auto pPastedNode = m_top;

		while (pCopiedNode->next != nullptr)
		{
			pPastedNode->next = std::make_shared<Node>(*pCopiedNode->next);

			pCopiedNode = pCopiedNode->next;
			pPastedNode = pPastedNode->next;
		}

		m_size = copiedStack.m_size;
	}
}

CStringStack::~CStringStack() noexcept
{
	Clear();
}