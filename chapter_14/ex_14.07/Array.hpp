#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename A = int, int size = 10>
class Array
{
    friend std::ostream & operator<<(std::ostream &, const Array<A, size> &);
    friend std::istream & operator>>(std::istream &, const Array<A, size> &);
public:
    Array();
    Array(const Array &);
    ~Array();
    int getSize() const;

    const Array<A, size> & operator=(const Array<A, size> &);
    bool operator==(const Array<A, size> &) const;

    bool operator!=(const Array<A, size> &right) const
    {
        return !(*this == right);
    }

    A & operator[](int);
    A operator[](int) const;
private:
    int size_;
    A *ptr_;
};


template <typename A, int size>
Array<A, size>::Array()
{
    size_ = (size > 0 ? size : 10);
    ptr_ = new A[size_];
    for (int i = 0; i < size_; ++i) {
        ptr_[i] = 0;
    }
}

template <typename A, int size>
Array<A, size>::Array(const Array<A, size> &arrayToCopy)
    : size_(arrayToCopy.size_)
{
    ptr_ = new A[size_];
    for (int i = 0; i < size_; ++i) {
        ptr_[i] = arrayToCopy.ptr_[i];
    }
}

template <typename A, int size>
Array<A, size>::~Array()
{
    delete [] ptr_;
}

template <typename A, int size>
int 
Array<A, size>::getSize() const
{
    return size_;
}

template <typename A, int size>
const Array<A, size> & 
Array<A, size>::operator=(const Array<A, size> &right)
{
    if (size_ != right.size_) {
        delete [] ptr_;
        size_ = right.size_;
        ptr_ = new A[size_];
    }
    for (int i = 0; i < size_; ++i) {
        ptr_[i] = right.ptr_[i];
    }
    return *this;
}

template <typename A, int size>
bool 
Array<A, size>::operator==(const Array<A, size> &right) const
{
    if (size_ != right.size_) {
        return false;
    }
    for (int i = 0; i < size_; ++i) {
        if (ptr_[i] != right.ptr_[i]) {
            return false;
        }
    }
    return true;
}

template <typename A, int size>
A & 
Array<A, size>::operator[](int subscript)
{
    if (subscript < 0 || subscript >= size_) {
        std::cerr << "Error 1: out of rage." << std::endl;
        ::exit(1);
    }
    return ptr_[subscript];
}

template <typename A, int size>
A 
Array<A, size>::operator[](int subscript) const
{
    if (subscript < 0 || subscript >= size_) {
        std::cerr << "Error 1: out of rage." << std::endl;
        ::exit(1);
    }
    return ptr_[subscript];
}

template <typename A, int size>
std::ostream &
operator<<(std::ostream &output, const Array<A, size> &array)
{
    for (int i = 0; i < array.size_; ++i) {
        output << array.ptr_[i] << ' ';
    }
    std::cout << std::endl;
    return output;
}

template <typename A, int size>
std::istream &
operator>>(std::istream &input, const Array<A, size> & array)
{
    for (int i = 0; i < array.size_; ++i) {
        input >> array.ptr_[i];
    }
    return input;
}

#endif

