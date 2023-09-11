#pragma once
#include <stack>
#include <iostream>

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

	class BinarySearchTree
	{
	private:
		Node* mpRoot;
	public:
		BinarySearchTree()
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
			if (parent == nullptr)
			{
				return CreateNode(data);
			}
			if (data < parent->mpData)
			{
				parent->mpLeft = Insert(parent->mpLeft, data);
			}
			else if (data > parent->mpData)
			{
				parent->mpRight = Insert(parent->mpRight, data);
			}

			return parent;
		}
	public:
		void Visit(Node* node) { std::cout << node->mpData << " "; }
		void InOrder(Node* node)
		{
			if (node == nullptr) return;
			InOrder(node->mpLeft);
			Visit(node);
			InOrder(node->mpRight);
		}
	};
}

void BSTTest()
{
	using namespace mytree;

	BinarySearchTree bst;

	auto root = bst.Insert(nullptr, 8);

	bst.Insert(root, 3);
	bst.Insert(root, 10);
	bst.Insert(root, 1);
	bst.Insert(root, 6);

	bst.InOrder(root);
}