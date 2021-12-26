#if !defined(MY_LIB_H)
#define MY_LIB_H

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

/* Print all element of container */

template <class TContainer>
void printContainer(TContainer &container, int padding = 0) {
    /*
     * Use `T& container` instead of `T container`.
     * Otherwise, if you pass a array, container will have type of pointer.
     * Then for-range of a pointer is a compile error
     */
    for (auto &&ele : container) {
        std::cout << ele << " ";
    }
    std::cout << "\n";
}

/* Vector utils */

std::vector<int> generateVector(int size) {
    std::vector<int> numbers(size);
    for (int i = 0; i < size; i++) {
        numbers[i] = i + 1;
    }
    std::vector<int> output;
    while (size > 0) {
        int newIndex = rand() % size;
        output.push_back(numbers[newIndex]);
        numbers.erase(numbers.begin() + newIndex);
        size--;
    }
    return output;
}

std::vector<int> generateSortedVector(int maxSize) {
    std::vector<int> numbers;
    numbers.reserve(maxSize);
    for (int i = 1; i <= numbers.capacity(); i++) {
        if (rand() % 2 == 0) {
            numbers.emplace_back(i);
        }
    }
    return numbers;
}

void printVectorWithIndex(std::vector<int> &data, int width = 3) {
    std::cout << "Index: ";
    for (int i = 0; i < data.size(); i++) {
        std::cout << std::setw(width) << std::left << i;
    }
    std::cout << "\nValue: ";
    for (int i = 0; i < data.size(); i++) {
        std::cout << std::setw(width) << std::left << data[i];
    }
    std::cout << "\n";
}

#endif  // MY_LIB_H
