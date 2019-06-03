#pragma once

class CStringStack
{
public:
	CStringStack() = default;
	CStringStack(CStringStack const& other);
	CStringStack(CStringStack&& other);

	void Push(std::string const& str);
	void Pop();

	const std::string& GetTop() const;
	size_t GetSize() const;
	bool IsEmpty() const;

	void Clear() noexcept;

	CStringStack& operator=(CStringStack const& other);
	CStringStack& operator=(CStringStack&& other);

	~CStringStack() noexcept;

private:
	struct Node
	{
		Node(std::string const& str, std::shared_ptr<Node> const& nextNode)
			: data(str)
			, next(nextNode)
		{
		}

		std::string data;
		std::shared_ptr<Node> next = nullptr;
	};

	void CopyElements(CStringStack const& copiedStack);

	size_t m_size = 0;
	std::shared_ptr<Node> m_top = nullptr;
};
