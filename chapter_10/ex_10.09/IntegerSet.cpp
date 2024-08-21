#include "IntegerSet.hpp"

#include <iostream>
#include <cassert>

IntegerSet::IntegerSet()
{
    for (int i = 0; i < SIZE; ++i) {
        set_[i] = false;
    }
}

IntegerSet::IntegerSet(int set[], int size)
{
    assert(size > 0);
    for (int i = 0; i < SIZE; ++i) {
        set_[i] = false;
    }
    for (int i = 0; i < size; ++i) {
        if (set[i] >= 0 && set[i] < SIZE) {
            set_[set[i]] = true;
        }
    }
}

void
IntegerSet::unionOfSets(IntegerSet set1, IntegerSet set2)
{
    IntegerSet set3;
    for (int i = 0; i < SIZE; ++i) {
        if (set1.set_[i] || set2.set_[i]) {
            set_[i] = true;
        }
    }
}

void
IntegerSet::intersectionOfSets(IntegerSet set1, IntegerSet set2)
{
    IntegerSet set3;
    for (int i = 0; i < SIZE; ++i) {
        if (set1.set_[i] && set2.set_[i]) {
            set_[i] = true;
        }
    }
}

void
IntegerSet::insertElement(int element)
{
    if (element >= 0 && element < SIZE) {
        set_[element] = true;
    }
}

void
IntegerSet::deleteElement(int element)
{
    if (element >= 0 && element < SIZE) {
        set_[element] = false;
    }
}

void
IntegerSet::printSet()
{
    IntegerSet nullSet;
    if (this->isEqualTo(nullSet)) {
        std::cout << '-' << std::endl;
        return;
    }
    for (int i = 0; i < SIZE; ++i) {
        if (set_[i]) {
            std::cout << i << ' ';
        }
    }
    std::cout << std::endl;
}

bool
IntegerSet::isEqualTo(IntegerSet set)
{
    for (int i = 0; i < SIZE; ++i) {
        if (set_[i] != set.set_[i]) {
            return false;
        }
    }
    return true;
}

