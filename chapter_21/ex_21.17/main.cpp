#include <iostream>
#include <cstring>

#include "Tree.hpp"
#include "TreeNode.hpp"

int
main()
{
    std::cout << std::endl;

    Tree<char *> stringTree;

    std::cout << "Enter text: ";
    char *text;
    std::cin.getline(text, 50);
    std::cout << text << std::endl;
    char *tok = strtok(text, " ");
    while (tok != NULL) {
        stringTree.insertNode(tok);
        tok = strtok(NULL, " ");
    }

    std::cout << "\nPreorder traversal." << std::endl;
    stringTree.preOrderTraversal();

    std::cout << "\nInorder traversal." << std::endl;
    stringTree.inOrderTraversal();

    std::cout << "\nPostorder traversal." << std::endl;
    stringTree.postOrderTraversal();

    std::cout << std::endl;
    return 0;
}

