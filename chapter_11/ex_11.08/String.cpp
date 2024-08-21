#include "String.hpp"

#include <iomanip>
#include <cstring>

String::String(const char *string1)
    :length_((string1 != nullptr) ? strlen(string1) : 0)
{
    std::cout << "Convertion (and default) constructor: " << string1 << std::endl;
    setString(string1);
}

String::String(const String &copy)
    : length_(copy.length_)
{
    std::cout << "Copy constructor: " << copy.stringPtr_ << std::endl;
    setString(copy.stringPtr_);
}

String::~String()
{
    std::cout << "Destructor: " << stringPtr_ << std::endl;
    delete[] stringPtr_;
}

int
String::getLength()
{
    return length_;
}

const String &
String::operator=(const String &right)
{
    std::cout << "operator= called" << std::endl;

    if (&right != this) {
        delete [] stringPtr_;
        length_ = right.length_;
        setString(right.stringPtr_);
    } else {
        std::cout << "Selfassignment." << std::endl;
    }
    return *this;
}

const String 
String::operator+(const String &right)
{
    std::cout << "operator+ called" << std::endl;

    size_t newLength = length_ + right.length_;
    char temporary[newLength + 1];

    strcpy(temporary, stringPtr_);
    strcpy(temporary + length_, right.stringPtr_);
    temporary[newLength] = '\0';
    String newString(temporary);

    return newString;
}

const String &
String::operator+=(const String &right)
{
    std::cout << "operator+= called" << std::endl;

    size_t newLength = length_ + right.length_;
    char *temporaryPtr = new char[newLength + 1];

    strcpy(temporaryPtr, stringPtr_);
    strcpy(temporaryPtr + length_, right.stringPtr_);

    delete []stringPtr_;
    stringPtr_ = temporaryPtr;
    length_ = newLength;

    return *this;
}

char &
String::operator[](int subscript)
{
    if (subscript < 0 || subscript >= length_) {
        std::cerr << "Error 1: Subscript " << subscript << "out of rage." << std::endl;
        ::exit(1);
    }
    return stringPtr_[subscript];
}

char
String::operator[](int subscript) const
{
    if (subscript < 0 || subscript >= length_) {
        std::cerr << "Error 1: Subscript " << subscript << "out of rage." << std::endl;
        ::exit(1);
    }
    return stringPtr_[subscript];
}

void
String::setString(const char *string1)
{
    stringPtr_ = new char[length_ + 1];

    if (string1 != nullptr) {
        strcpy(stringPtr_, string1);
    } else {
        stringPtr_[0] = '\0';
    }
}

std::ostream
&operator<<(std::ostream &output, const String &string1)
{
    output << string1.stringPtr_;
    return output;
}

std::istream
&operator>>(std::istream &input, String &string1)
{
    static const int limit = 100;
    char temporary[limit];
    input >> std::setw(limit) >> temporary;
    string1 = temporary;
    return input;
}

