#pragma once
#ifndef binarytree_h
#define binarytree_h

#include <iostream>
#include <queue>
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

		Node* InsertLeft(Node* parent, int value)
		{
			parent->mpLeft = CreateNode(value);
			return parent->mpLeft;
		}
		Node* InsertRight(Node* parent, int value)
		{
			parent->mpRight = CreateNode(value);
			return parent->mpRight;
		}

	public:
		void Visit(Node* node) { std::cout << node->mpData << " "; }

		void BreadthFirstSearch()
		{
			std::queue<Node*> q;

			q.push(mpRoot);

			while (!q.empty())
			{
				auto node = q.front();
				Visit(node);
				q.pop();

				if (node->mpLeft)
				{
					q.push(node->mpLeft);
				}
				if (node->mpRight != nullptr)
				{
					q.push(node->mpRight);
				}
			}			
		}
		void DepthFirstSearch()
		{
			std::stack<Node*> s;

			s.push(mpRoot);

			while (!s.empty())
			{
				auto node = s.top();
				Visit(node);
				s.pop();

				if (node->mpRight) s.push(node->mpRight);
				if (node->mpLeft) s.push(node->mpLeft);
			}
		}

		
		void DFSRecursive(Node* node)
		{
			//base case
			if (!node)
			{
				return;
			}

			Visit(node);

			//recursive case
			DFSRecursive(node->mpLeft);
			DFSRecursive(node->mpRight);
		}	

		int x{};

		void DFSSUM(Node* node)
		{		
			if (!node)			
			{
				return;
			}

			x += node->mpData;

			DFSSUM(node->mpLeft);
			DFSSUM(node->mpRight);					
		}		


		int SUM(Node * node)
		{
			DFSSUM(node);
			return x;
		}

		bool Search(Node* node, int value)
		{
			//base case
			if (!node) return false;

			return node->mpData == value || Search(node->mpLeft, value) || Search(node->mpRight, value);
		}

		int depth{-1};
		int max{};
		void DEPTH(Node* node)
		{	
			depth++;
			//base case
			if (!node)
			{
				if (depth > max)
				{
					max = depth;
				}
				
				return;
			}			
			
			//recursive case
			DEPTH(node->mpLeft);
			depth--;
			DEPTH(node->mpRight);
			depth--;
		}

		int ShowDEPTH(Node* node)
		{
			DEPTH(node);
			return max;
		}
		
		void PreOrder(Node* node)
		{
			//base case
			if (!node)
			{
				return;
			}

			Visit(node);

			//recursive case
			DFSRecursive(node->mpLeft);
			DFSRecursive(node->mpRight);
		}

		void InOrder(Node* node)
		{
			//base case
			if (!node)
			{
				return;
			}			

			//recursive case
			DFSRecursive(node->mpLeft);
			Visit(node);
			DFSRecursive(node->mpRight);
		}


		void PostOrder(Node* node)
		{
			//base case
			if (!node)
			{
				return;
			}

			//recursive case
			DFSRecursive(node->mpLeft);			
			DFSRecursive(node->mpRight);
			Visit(node);
		}
	};
}

#endif