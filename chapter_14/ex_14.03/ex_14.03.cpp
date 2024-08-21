#include <iostream>

template <typename S>
void selectionSort(S [], const int);
template <typename S>
void printArray(const S [], const int);

int
main()
{
    std::cout << std::endl;
 
    const int size = 6;
    int arrayInt[size] = {2, 4, 6, 8, 0, -5};
    double arrayDouble[size] = {1.2, -5.1, 9.5, 0.7, 5.5, 0.0};
    char arrayChar[size] = {'a', 's', 'x', 'e', 't', 'o'};

    printArray(arrayInt, size);
    selectionSort(arrayInt, size);
    printArray(arrayInt, size);
    std::cout << std::endl;

    printArray(arrayDouble, size);
    selectionSort(arrayDouble, size);
    printArray(arrayDouble, size);
    std::cout << std::endl;

    printArray(arrayChar, size);
    selectionSort(arrayChar, size);
    printArray(arrayChar, size);

    std::cout << std::endl;
    return 0;
}

template <typename S>
void
selectionSort(S array[], const int size)
{
    for (int i = 0; i < size - 1; ++i) {
        int tempIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[tempIndex]) {
                tempIndex = j;
            }
        }
        std::swap(array[i], array[tempIndex]);
    }
}

template <typename S>
void
printArray(const S array[], const int size)
{
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

