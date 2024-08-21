#ifndef LISTNODE_HPP
#define LISTNODE_HPP

template<typename NODE> class List;

template<typename NODE>
class ListNode
{
    friend class List<NODE>;
public:
    ListNode(const NODE &);
    NODE getData() const;
private:
    NODE data_;
    ListNode<NODE> *nextPtr_;
};

template<typename NODE>
ListNode<NODE>::ListNode(const NODE &info)
    : data_(info), nextPtr_(0)
{
}

template<typename NODE>
NODE
ListNode<NODE>::getData() const
{
    return data_;
}

#endif

