#ifndef TREE_HPP
#define TREE_HPP

#include "TreeNode.hpp"

template<typename NODE> 
class Tree
{
public:
    Tree();
    void insertNode(const NODE &);
    void preOrderTraversal() const;
    void inOrderTraversal() const;
    void postOrderTraversal() const;
private:
    TreeNode<NODE> *rootPtr_;

    void insertNodeHelper(TreeNode<NODE> **, const NODE &);
    void preOrderHelper(TreeNode<NODE> *) const;
    void inOrderHelper(TreeNode<NODE> *) const;
    void postOrderHelper(TreeNode<NODE> *) const;
};

template<typename NODE>
Tree<NODE>::Tree()
{
    rootPtr_ = nullptr;
}

template<typename NODE>
void
Tree<NODE>::insertNode(const NODE &data)
{
    insertNodeHelper(&rootPtr_, data);
}

template<typename NODE>
void
Tree<NODE>::insertNodeHelper(TreeNode<NODE> **root, const NODE &data)
{
    if (*root == nullptr) {
        *root = new TreeNode<NODE>(data);
    } else if (data < (*root)->data_) {
        insertNodeHelper(&((*root)->leftPtr_), data);
    } else if (data > (*root)->data_) {
        insertNodeHelper(&((*root)->rightPtr_), data);
    } else {
        std::cout << data << "dup" << std::endl;
    }
}

template<typename NODE>
void
Tree<NODE>::preOrderTraversal() const
{
    preOrderHelper(rootPtr_);
}

template<typename NODE>
void
Tree<NODE>::preOrderHelper(TreeNode<NODE> *root) const
{
    if (root != nullptr) {
        std::cout << root->data_ << ' ';
        preOrderHelper(root->leftPtr_);
        preOrderHelper(root->rightPtr_);
    }
}

template<typename NODE>
void
Tree<NODE>::inOrderTraversal() const
{
    inOrderHelper(rootPtr_);
}

template<typename NODE>
void
Tree<NODE>::inOrderHelper(TreeNode<NODE> *root) const
{
    if (root != nullptr) {
        inOrderHelper(root->leftPtr_);
        std::cout << root->data_ << ' ';
        inOrderHelper(root->rightPtr_);
    }
}

template<typename NODE>
void
Tree<NODE>::postOrderTraversal() const
{
    postOrderHelper(rootPtr_);
}

template<typename NODE>
void
Tree<NODE>::postOrderHelper(TreeNode<NODE> *root) const
{
    if (root != nullptr) {
        postOrderHelper(root->leftPtr_);
        postOrderHelper(root->rightPtr_);
        std::cout << root->data_ << ' ';
    }
}

#endif

