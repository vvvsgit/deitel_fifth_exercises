#include <iostream>

#include "Tree.hpp"
#include "TreeNode.hpp"

int
main()
{
    std::cout << std::endl;

    Tree<int> intTree;
    int intValue;
    std::cout << "Enter 10 integers values:" << std::endl;

    for (int i = 0; i < 10; ++i) {
        std::cin >> intValue;
        intTree.insertNode(intValue);
    }

    std::cout << "\nPreorder traversal." << std::endl;
    intTree.preOrderTraversal();

    std::cout << "\nInorder traversal." << std::endl;
    intTree.inOrderTraversal();

    std::cout << "\nPostorder traversal." << std::endl;
    intTree.postOrderTraversal();

    std::cout << std::endl;
    return 0;
}

