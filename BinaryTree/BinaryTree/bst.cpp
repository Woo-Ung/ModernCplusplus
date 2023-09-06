#include <stack>

namespace mytree
{
	struct Node
	{
		int mpData;
		Node* mpLeft;
		Node* mpRight;

		Node(int data = 0, Node* pleft = nullptr, Node* pright = nullptr)
		{
			mpData = data;
			mpLeft = pleft;
			mpRight = pright;
		}
	};

	class BinaryTree
	{
	private:
		Node* mpRoot;
	public:
		BinaryTree()
		{
			mpRoot = CreateNode(0);
		}

		Node* CreateNode(int value, Node* pLeft = nullptr, Node* pRight = nullptr)
		{
			return new Node(value, pLeft, pRight);
		}
		Node* GetRoot() { return mpRoot; }
		Node* Insert(Node* parent, int data)
		{
			//rules
		}
	};
}