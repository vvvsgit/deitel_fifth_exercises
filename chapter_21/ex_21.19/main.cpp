#include <iostream>
#include <cstring>

#include "Tree.hpp"
#include "TreeNode.hpp"

int
main()
{
    std::cout << std::endl;

    Tree<int> tree;

    int quantity = 10;
    std::cout << "Enter " << quantity << " integers: ";
    for (int i = 0; i < quantity; ++i) {
        int number;
        std::cin >> number;
        tree.insertNode(number);
    }

    std::cout << "The depth is " << tree.depth() << std::endl;

    std::cout << "\nPreorder traversal." << std::endl;
    tree.preOrderTraversal();

    std::cout << "\nInorder traversal." << std::endl;
    tree.inOrderTraversal();

    std::cout << "\nPostorder traversal." << std::endl;
    tree.postOrderTraversal();

    std::cout << std::endl;
    return 0;
}

