#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "List.hpp"

template<typename QUEUE>
class Queue : private List<QUEUE>
{
public:
    void enqueue(const QUEUE &);
    bool dequeue(QUEUE &);
    bool isQueueEmpty() const;
    void printQueue() const;
};

template<typename QUEUE>
void 
Queue<QUEUE>::enqueue(const QUEUE &data)
{
    insertAtBack(data);
}

template<typename QUEUE>
bool
Queue<QUEUE>::dequeue(QUEUE &data)
{
    return removeFromFront(data);
}

template<typename QUEUE>
bool
Queue<QUEUE>::isQueueEmpty() const
{
    return isEmpty();
}

template<typename QUEUE>
void
Queue<QUEUE>::printQueue() const
{
    print();
}

#endif

