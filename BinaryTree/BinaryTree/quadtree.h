#pragma once
#ifndef quadtree_h
#define quadtree_h
#include <memory>

namespace mytree
{
	struct Point
	{
		int x;
		int y;

		Point() : x(0), y(0) {}
		Point(int x, int y)
		{
			this->x = x;
			this->y = y;
		}
	};

	struct Node
	{
		Point pos;
		int data;

		Node() : pos(), data(0) {}
		Node(Point p, int data)
		{
			this->pos = p;
			this->data = data;
		}
	};

	class QuadTree
	{
		Point topLeft;
		Point bottomRight;

		Node* node;

		std::unique_ptr<QuadTree> nw;
		std::unique_ptr<QuadTree> ne;
		std::unique_ptr<QuadTree> sw;
		std::unique_ptr<QuadTree> se;

	private:
		bool IsInBound(Point pt);

	public:
		QuadTree();
		QuadTree(Point tl, Point br);

		// n : ����ũ��, k : ����� ����
		// TimeComplexity : 0 (log n)
		// SpaceComplexity	: 0 (k log n)
		void Insert(Node* node);
	};

}

void QTTest();

#endif // !quadtree_h
