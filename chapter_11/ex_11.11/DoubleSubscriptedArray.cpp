#include "DoubleSubscriptedArray.hpp"

DoubleSubscriptedArray::DoubleSubscriptedArray(int row, int column)
    : row_(row > 0 ? row : 2)
    , column_(column > 0 ? column : 2)
{
    std::cout << "Constructor " << row_ << " " << column_ << std::endl;

    intPtr_ = new int [getLength()];

    for (int i = 0; i < getLength(); ++i) {
        intPtr_[i] = 0;
    }
}

DoubleSubscriptedArray::DoubleSubscriptedArray(const DoubleSubscriptedArray & copy)
    : row_(copy.row_)
    , column_(copy.column_)
{
    std::cout << "Copy constructor " << row_ << ' ' << column_ << std::endl;

    intPtr_ = new int [getLength()];

    for (int i = 0; i < getLength(); ++i) {
        intPtr_[i] = copy.intPtr_[i];
    }
}

DoubleSubscriptedArray::~DoubleSubscriptedArray()
{
    std::cout << "Destructor " << row_ << " " << column_ << std::endl;
    delete [] intPtr_;
}

int
DoubleSubscriptedArray::getRow()
{
    return row_;
}

int
DoubleSubscriptedArray::getColumn()
{
    return column_;
}

const int
DoubleSubscriptedArray::getLength() const
{
    return row_ * column_;
}

const DoubleSubscriptedArray &
DoubleSubscriptedArray::operator=(const DoubleSubscriptedArray &right)
{
    std::cout << "operator= called." << std::endl;
    if (this == &right) {
        std::cout << "Selfassignment." << std::endl;
        return *this;
    }
    if (row_ != right.row_ || column_ != right.column_) {
        delete [] intPtr_;
        row_ = right.row_;
        column_ = right.column_;
        intPtr_ = new int [getLength()];
    }
    for (int i = 0; i < getLength(); ++i) {
        intPtr_[i] = right.intPtr_[i];
    }
    return *this;
}

const bool
DoubleSubscriptedArray::operator==(const DoubleSubscriptedArray &right) const
{
    if (row_ != right.row_ || column_ != right.column_) {
        return false;
    }
    for (int i = 0; i < getLength(); ++i) {
        if (intPtr_[i] != right.intPtr_[i]) {
            return false;
        }
    }
    return true;
}

const bool
DoubleSubscriptedArray::operator!=(const DoubleSubscriptedArray &right) const
{
    return !(*this == right);
}

const int
DoubleSubscriptedArray::operator()(const int row, const int column) const
{
    if (row < 0 || row >= row_ || column < 0 || column >= column_) {
        std::cout << "Error 1: out of rage." << std::endl;
        ::exit(1);
    }
    return intPtr_[row * column_ + column];
}

int &
DoubleSubscriptedArray::operator()(const int row, const int column)
{
    if (row < 0 || row >= row_ || column < 0 || column >= column_) {
        std::cout << "Error 1: out of rage." << std::endl;
        ::exit(1);
    }
    return intPtr_[row * column_ + column];
}

//friend
std::ostream &
operator<<(std::ostream &output, const DoubleSubscriptedArray &array)
{
    for (int i = 0; i < array.getLength(); ++i) {
        std::cout << array.intPtr_[i] << ' ';
        if ((i + 1) % array.column_ == 0) {
            std::cout << std::endl;
        }
    }
    return output;
}

//friend
std::istream &
operator>>(std::istream &input, DoubleSubscriptedArray &array)
{
    for (int i = 0; i < array.getLength(); ++i) {
        input >> array.intPtr_[i];
    }
    return input;
}

