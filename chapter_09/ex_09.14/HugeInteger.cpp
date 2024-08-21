#include "HugeInteger.hpp"

#include <iostream>


HugeInteger::HugeInteger()
{
    setHugeInteger();
}

void
HugeInteger::setHugeInteger()
{
    for (int i = 0; i < SIZE; ++i) {
        hugeInteger_[i] = '0';
    }
    hugeInteger_[SIZE] = '\0';
}

void
HugeInteger::input()
{
    char array[SIZE];
    std::cin >> array;
    int counter;
    for (counter = 0; array[counter] != '\0'; ++counter) {
        if (array[counter] < '0' || array[counter] > '9') {
            std::cerr << "Error 1: not integer." << std::endl;
            ::exit(1);
        }
    }
    for (int i = SIZE - counter, j = 0; i < SIZE; ++i, ++j) {
        hugeInteger_[i] = array[j];
    }
}

void
HugeInteger::output()
{
    if (isZero()) {
        std::cout << '0' << std::endl;
        return;
    }
    int startIndex;
    for (startIndex = 0; startIndex < SIZE; ++startIndex) {
        if (hugeInteger_[startIndex] != '0') {
            break;
        }
    }
    for (; startIndex < SIZE; ++startIndex) {
        std::cout << hugeInteger_[startIndex];
    }
    std::cout << std::endl;
}

void
HugeInteger::add(HugeInteger integer)
{
    int nextDigit = 0;
    for (int i = SIZE - 1; i >= 0; --i) {
        int digitSum = (static_cast<int>(hugeInteger_[i]) - 48) + (static_cast<int>(integer.hugeInteger_[i]) - 48);
        nextDigit += digitSum % 10;
        if (nextDigit == 10) {
            hugeInteger_[i] = '0';
            nextDigit = 1;
            continue;
        }
        hugeInteger_[i] = static_cast<char>(nextDigit + 48);
        nextDigit = digitSum / 10;
    }
}

void
HugeInteger::substract(HugeInteger integer)
{
    if (this->isLessThan(integer)) {
        std::cout << "Getting negative number, change places." << std::endl;
        return;
    }
    int nextDigit = 0;
    for (int i = SIZE - 1; i >= 0; --i) {
        if (hugeInteger_[i] < integer.hugeInteger_[i]) {
            int j;
            for (j = i - 1; hugeInteger_[j] == 0; --j);
                hugeInteger_[j] -= 1;
            for (++j; j > i; ++j) {
                hugeInteger_[j] = '9';
            }
            nextDigit = 10;
        }
        int digitDif = (nextDigit + static_cast<int>(hugeInteger_[i]) - 48) - (static_cast<int>(integer.hugeInteger_[i]) - 48);
        hugeInteger_[i] = static_cast<char>(digitDif + 48);
        nextDigit = 0;
    }
}

bool
HugeInteger::isEqualTo(HugeInteger integer)
{
    for (int i = 0; i < SIZE; ++i) {
        if (hugeInteger_[i] != integer.hugeInteger_[i]) {
            return false;
        }
    }
    return true;
}

bool
HugeInteger::isNotEqualTo(HugeInteger integer)
{
    return !isEqualTo(integer);
}

bool
HugeInteger::isGreaterThan(HugeInteger integer)
{
    for (int i = 0; i < SIZE; ++i) {
        if (hugeInteger_[i] > integer.hugeInteger_[i]) {
            return true;
        }
        if (hugeInteger_[i] < integer.hugeInteger_[i]) {
            return false;
        }
    }
    return false;
}

bool
HugeInteger::isLessThan(HugeInteger integer)
{
    for (int i = 0; i < SIZE; ++i) {
        if (hugeInteger_[i] < integer.hugeInteger_[i]) {
            return true;
        }
        if (hugeInteger_[i] > integer.hugeInteger_[i]) {
            return false;
        }
    }
    return false;
}

bool
HugeInteger::isGreaterThanOrEqualTo(HugeInteger integer)
{
    return !isLessThan(integer);
}

bool
HugeInteger::isLessThanOrEqualTo(HugeInteger integer)
{
    return !isGreaterThan(integer);
}

bool
HugeInteger::isZero()
{
    for (int i = 0; i < SIZE; ++i) {
        if (hugeInteger_[i] != '0') {
            return false;
        }
    }
    return true;
}

