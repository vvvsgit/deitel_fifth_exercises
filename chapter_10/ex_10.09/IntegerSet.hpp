#ifndef INTEGERSET_HPP
#define INTEGERSET_HPP

const int SIZE = 101;

class IntegerSet
{
public:
    IntegerSet();
    IntegerSet(int [], int);

    void unionOfSets(IntegerSet, IntegerSet);
    void intersectionOfSets(IntegerSet, IntegerSet);
    void insertElement(int);
    void deleteElement(int);
    void printSet();
    bool isEqualTo(IntegerSet);
private:
    bool set_[SIZE];
};

#endif

