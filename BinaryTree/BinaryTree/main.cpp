#include <iostream>
#include "binarytree.h"

using namespace mytree;

int main()
{
    BinaryTree myTree;

    auto pRoot = myTree.GetRoot();
    pRoot->mpData = 1;

    auto pNode = myTree.InsertLeft(pRoot, 2);
    myTree.InsertLeft(pNode, 4);
    myTree.InsertRight(pNode, 5);

    pNode = myTree.InsertRight(pRoot, 3);
    myTree.InsertLeft(pNode, 6);
    myTree.InsertRight(pNode, 7);



  /*  myTree.BreadthFirstSearch();
    std::cout << std::endl;

    myTree.DepthFirstSearch();
    std::cout << std::endl;

    myTree.DFSRecursive(myTree.GetRoot());
    std::cout << std::endl;

    myTree.PostOrder(myTree.GetRoot());
    std::cout << std::endl;

    myTree.InOrder(myTree.GetRoot());
    std::cout << std::endl;*/

    std::cout << myTree.ShowDEPTH(myTree.GetRoot()) << std::endl;
}