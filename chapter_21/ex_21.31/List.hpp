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
    bool isEmpty() const;
    void print() const;
    int getSize() const;
    NODE operator[](const int) const;
    NODE & operator[](const int);
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
int
List<NODE>::getSize() const
{
    if (isEmpty()) {
        return 0;
    }
    ListNode<NODE> *currentPtr = firstPtr_;
    int size = 0;
    while (currentPtr != nullptr) {
        currentPtr = currentPtr->nextPtr_;
        ++size;
    }
    return size;
}

template<typename NODE>
NODE
List<NODE>::operator[](const int index) const
{
    if (index < 0 || index >= getSize()) {
        std::cerr << "Error 1: out of rage." << std::endl;
        ::exit(1);
    }

    ListNode<NODE> *currentPtr = firstPtr_;
    int size = 0;
    while (size < index) {
        currentPtr = currentPtr->nextPtr_;
        ++size;
    }
    return currentPtr->data_;
}

template<typename NODE>
NODE &
List<NODE>::operator[](const int index)
{
    if (index < 0 || index >= getSize()) {
        std::cerr << "Error 1: out of rage." << std::endl;
        ::exit(1);
    }

    ListNode<NODE> *currentPtr = firstPtr_;
    int size = 0;
    while (size < index) {
        currentPtr = currentPtr->nextPtr_;
        ++size;
    }
    return currentPtr->data_;
}

#endif

