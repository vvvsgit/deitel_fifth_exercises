#include <iostream>

void bubbleSort(int [], const int);
void printArray(const int [], const int);

int
main()
{
    std::cout << std::endl;

    const int size = 10;
    int array[size] = {5, 4, 9, 0, 8, 3, 6, 7, 1, 2};

    printArray(array, size);
    bubbleSort(array, size);
    printArray(array, size);

    std::cout << std::endl;
    return 0;
}

void
bubbleSort(int array[], const int size)
{
    for (int i = size; i > 0; --i) {
        for (int j = 1; j < i; ++j) {
            if (array[j - 1] > array[j]) {
                std::swap(array[j - 1], array[j]);
            }
        }
    }
}

void
printArray(const int array[], const int size)
{
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

