#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

#include "ListNode.hpp"

template<typename NODE>
class List
{
public:
    List();
    ~List();
    void insertAtFront(const NODE &);
    void insertAtBack(const NODE &);
    bool removeFromFront(NODE &);
    bool removeFromBack(NODE &);
    void concatenate(List<char> &, const List<char> &);
    void merge(List<int> &, List<int> &);
    bool isEmpty() const;
    void print() const;
private:
    ListNode<NODE> *firstPtr_;
    ListNode<NODE> *lastPtr_;

    ListNode<NODE> *getNewNode(const NODE &);
};

template<typename NODE>
List<NODE>::List()
    : firstPtr_(0), lastPtr_(0)
{
}

template<typename NODE>
List<NODE>::~List()
{
    if (!isEmpty()) {
        std::cout << "Destroying nodes...\n";

        ListNode<NODE> *currentPtr = firstPtr_;
        ListNode<NODE> *tempPtr = nullptr;

        while (currentPtr != nullptr) {
            tempPtr = currentPtr;
            std::cout << tempPtr->data_ << std::endl;
            currentPtr = currentPtr->nextPtr_;
            delete tempPtr;
        }
    }
    std::cout << "All nodes destroyed." << std::endl;
}

template<typename NODE>
void
List<NODE>::insertAtFront(const NODE &value)
{
    ListNode<NODE> *newPtr = getNewNode(value);

    if (isEmpty()) {
        firstPtr_ = lastPtr_ = newPtr;
    } else {
        newPtr->nextPtr_ = firstPtr_;
        firstPtr_ = newPtr;
    }
}

template<typename NODE>
void
List<NODE>::insertAtBack(const NODE &value)
{
    ListNode<NODE> *newPtr = getNewNode(value);

    if (isEmpty()) {
        firstPtr_ = lastPtr_ = newPtr;
    } else {
        lastPtr_->nextPtr = newPtr;
        lastPtr_ = newPtr;
    }
}

template<typename NODE>
bool
List<NODE>::removeFromFront(NODE &value)
{
    if (isEmpty()) {
        return false;
    } else {
        ListNode<NODE> *tempPtr = firstPtr_;

        if (firstPtr_ == lastPtr_) {
            firstPtr_ = lastPtr_ = nullptr;
        } else {
            firstPtr_ = firstPtr_->nextPtr_;
        }

        value = tempPtr->data_;
        delete tempPtr;
        return true;
    }
}

template<typename NODE>
bool
List<NODE>::removeFromBack(NODE &value)
{
    if (isEmpty()) {
        return false;
    } 
    ListNode<NODE> *tempPtr = lastPtr_;

    if (firstPtr_ == lastPtr_) {
        firstPtr_ = lastPtr_ = nullptr;
    } else {
        List<NODE> *currentPtr = firstPtr_;

        while (currentPtr->nextPtr_ != lastPtr_) {
            currentPtr = currentPtr->nextPtr_;
        }
        lastPtr_ = currentPtr;
        lastPtr_->nextPtr = nullptr;
    }
    value = tempPtr->data_;
    delete tempPtr;
    return true;
}

template<typename NODE>
bool
List<NODE>::isEmpty() const
{
    return firstPtr_ == nullptr;
}

template<typename NODE>
void
List<NODE>::print() const
{
    if (isEmpty()) {
        std::cout << "The list is empty." << std::endl;
    } else {
        ListNode<NODE> *currentPtr = firstPtr_;
        std::cout << "The list is: ";
        while (currentPtr != nullptr) {
            std::cout << currentPtr->data_ << ' ';
            currentPtr = currentPtr->nextPtr_;
        }
        std::cout << std::endl;
    }
}

template<typename NODE>
ListNode<NODE> *
List<NODE>::getNewNode(const NODE &value)
{
    return new ListNode<NODE>(value);
}

template<typename NODE>
void 
List<NODE>::concatenate(List<char> &first, const List<char> &second)
{
    ListNode<char> *currentPtr = second.firstPtr_;
    while (currentPtr != nullptr) {
        first.insertAtBack(currentPtr->data_);
        currentPtr = currentPtr->nextPtr_;
    }
}

template<typename NODE>
void 
List<NODE>::merge(List<int> &one, List<int> &two)
{
    ListNode<int> *onePtr = one.firstPtr_;
    ListNode<int> *twoPtr = two.firstPtr_;
    while (onePtr != nullptr || twoPtr != nullptr) {
        if (onePtr != nullptr && twoPtr != nullptr) {
            if (onePtr->data_ < twoPtr->data_) {
                insertAtBack(onePtr->data_);
                onePtr = onePtr->nextPtr_;
            } else {
                insertAtBack(twoPtr->data_);
                twoPtr = twoPtr->nextPtr_;
            }
        } else if (onePtr != nullptr) {
            insertAtBack(onePtr->data_);
            onePtr = onePtr->nextPtr_;
        } else {
            insertAtBack(twoPtr->data_);
            twoPtr = twoPtr->nextPtr_;
        }
    }
}

#endif

