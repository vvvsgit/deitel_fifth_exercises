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
    void deleteNode(const NODE &);
    void preOrderTraversal() const;
    void inOrderTraversal() const;
    void postOrderTraversal() const;
    int depth() const;
    TreeNode<NODE> * binaryTreeSearch(const NODE &);
private:
    TreeNode<NODE> *rootPtr_;

    void insertNodeHelper(TreeNode<NODE> **, const NODE &);
    void preOrderHelper(TreeNode<NODE> *) const;
    void inOrderHelper(TreeNode<NODE> *) const;
    void postOrderHelper(TreeNode<NODE> *) const;
    int depthHelper(TreeNode<NODE> *, int) const;
    void deleter(TreeNode<NODE> *);
    TreeNode<NODE> * searchHelper(TreeNode<NODE> *, const NODE &);
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
Tree<NODE>::deleteNode(const NODE &data)
{
    if (nullptr == binaryTreeSearch(data)) {
        return;
    }
    TreeNode<NODE> *tempPtr = rootPtr_;
    TreeNode<NODE> *parentPtr = tempPtr;
    if (rootPtr_->data_ == data) {
        std::cout << "Not implemented case." << std::endl;
        return;
    }

    bool isLeft;
    while (tempPtr->data_ != data) {
        parentPtr = tempPtr;
        if (data < tempPtr->data_) {
            isLeft = true;
            tempPtr = tempPtr->leftPtr_;
        } else {
            isLeft = false;
            tempPtr = tempPtr->rightPtr_;
        }
    }

    if (tempPtr->leftPtr_ == nullptr && tempPtr->rightPtr_ == nullptr) {
        if (isLeft) {
            parentPtr->leftPtr_ = nullptr;
        } else {
            parentPtr->rightPtr_ = nullptr;
        }
        delete tempPtr;
        return;
    }

    if (tempPtr->leftPtr_ != nullptr && tempPtr->rightPtr_ == nullptr) {
        if (isLeft) {
            parentPtr->leftPtr_ = tempPtr->leftPtr_;
        } else {
            parentPtr->rightPtr_ = tempPtr->leftPtr_;
        }
        delete tempPtr;
        return;
    } else if (tempPtr->leftPtr_ == nullptr && tempPtr->rightPtr_ != nullptr) {
        if (isLeft) {
            parentPtr->leftPtr_ = tempPtr->rightPtr_;
        } else {
            parentPtr->rightPtr_ = tempPtr->rightPtr_;
        }
        delete tempPtr;
        return;
    }

    TreeNode<NODE> *replacementNode = tempPtr;
    TreeNode<NODE> *replacementNodeParent = replacementNode;
    while (replacementNode->rightPtr_ != nullptr) {
        replacementNodeParent = replacementNode;
        replacementNode = replacementNode->rightPtr_;
    }
    if (replacementNode->leftPtr_ == nullptr) {
        if (isLeft) {
            parentPtr->leftPtr_ = replacementNode;
        } else {
            parentPtr->rightPtr_ = replacementNode;
        }
        replacementNodeParent->rightPtr_ = nullptr;
        replacementNode->rightPtr_ = tempPtr->rightPtr_;
        delete tempPtr;
    } else {
        if (isLeft) {
            parentPtr->leftPtr_ = replacementNode;
        } else {
            parentPtr->rightPtr_ = replacementNode;
        }
        replacementNodeParent->rightPtr_ = replacementNode->leftPtr_;
        replacementNode->rightPtr_ = tempPtr->rightPtr_;
        delete tempPtr;
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

template<typename NODE>
TreeNode<NODE> *
Tree<NODE>::binaryTreeSearch(const NODE &data)
{
    return searchHelper(rootPtr_, data);
}

template<typename NODE>
TreeNode<NODE> *
Tree<NODE>::searchHelper(TreeNode<NODE> *root, const NODE &data)
{
    if (root == nullptr) {
        std::cout << "No such data." << std::endl;
        return nullptr;
    } else if (data < root->data_) {
        return searchHelper(root->leftPtr_, data);
    } else if (data > root->data_) {
        return searchHelper(root->rightPtr_, data);
    }
    return root;
}

#endif

