#ifndef TREE_HPP
#define TREE_HPP

#include "TreeNode.hpp"

template<typename NODE> 
class Tree
{
public:
    Tree();
    ~Tree();
    void insertNode(const NODE &);
    void preOrderTraversal() const;
    void inOrderTraversal() const;
    void postOrderTraversal() const;
    int depth() const;
private:
    TreeNode<NODE> *rootPtr_;

    void insertNodeHelper(TreeNode<NODE> **, const NODE &);
    void preOrderHelper(TreeNode<NODE> *) const;
    void inOrderHelper(TreeNode<NODE> *) const;
    void postOrderHelper(TreeNode<NODE> *) const;
    int depthHelper(TreeNode<NODE> *, int) const;
    void deleter(TreeNode<NODE> *);
};

template<typename NODE>
Tree<NODE>::Tree()
{
    rootPtr_ = nullptr;
}

template<typename NODE>
Tree<NODE>::~Tree()
{
    deleter(rootPtr_);
}

template<typename NODE>
void
Tree<NODE>::deleter(TreeNode<NODE> *root)
{
    if (root != nullptr) {
        deleter(root->leftPtr_);
        deleter(root->rightPtr_);
        std::cout << "Deleting " << root->data_ << std::endl;
        delete root;
    }
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

template<typename NODE>
int
Tree<NODE>::depth() const
{
    if (rootPtr_ == nullptr) {
        return 0;
    }
    return depthHelper(rootPtr_, 1);
}

template<typename NODE>
int
Tree<NODE>::depthHelper(TreeNode<NODE> *root, int level) const
{
    if (root->leftPtr_ == nullptr && root->rightPtr_ == nullptr) {
        return level;
    } else if (root->leftPtr_ != nullptr && root->rightPtr_ == nullptr) {
        return depthHelper(root->leftPtr_, level + 1);
    } else if (root->leftPtr_ == nullptr && root->rightPtr_ != nullptr) {
        return depthHelper(root->rightPtr_, level + 1);
    }
    const int left = depthHelper(root->leftPtr_, level + 1);
    const int right = depthHelper(root->rightPtr_, level + 1);
    return (left > right ? left : right);
}

#endif

