#ifndef TREENODE_HPP
#define TREENODE_HPP

template<typename NODE> class Tree;

template<typename NODE>
class TreeNode
{
    friend class Tree<NODE>;
public:
    TreeNode(const NODE &);
    NODE getData() const;
private:
    TreeNode<NODE> *leftPtr_;
    NODE data_;
    TreeNode<NODE> *rightPtr_;
};

template<typename NODE>
TreeNode<NODE>::TreeNode(const NODE &data)
    : leftPtr_(nullptr)
    , data_(data)
    , rightPtr_(nullptr)
{
}

template<typename NODE>
NODE
TreeNode<NODE>::getData() const
{
    return data_;
}

#endif

