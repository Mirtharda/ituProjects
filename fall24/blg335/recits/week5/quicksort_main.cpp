#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "quicksort_pivotting.h"


void printArray(const std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// Function pointer type for partition functions
typedef int (*PartitionFunc)(std::vector<int>&, int, int);

// QuickSort function
void quickSort(std::vector<int>& arr, int low, int high, PartitionFunc partitionFunc) {
    if (low < high) {
        int pi = partitionFunc(arr, low, high);
        quickSort(arr, low, pi - 1, partitionFunc);
        quickSort(arr, pi + 1, high, partitionFunc);
    }
}
int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <pivotting_function> <array_size> <order>" << std::endl;
        return 1;
    }

    std::string pivottingFunction = argv[1];
    int arraySize = std::stoi(argv[2]);
    std::string order = argv[3];
    PartitionFunc partitionFunc;

    if (pivottingFunction == "last") {
        partitionFunc = partitionLast;
    } else if (pivottingFunction == "random") {
        partitionFunc = partitionRandom;
    } else if (pivottingFunction == "median") {
        partitionFunc = partitionMedianOfThree;
    } else {
        std::cerr << "Invalid pivotting function. Use 'last', 'random', or 'median'." << std::endl;
        return 1;
    }

    std::vector<int> arr(arraySize);
    for (int i = 0; i < arraySize; ++i) {
        arr[i] = i;
    }

    if (order == "ascending") {
        // Already sorted in ascending order
    } else if (order == "descending") {
        std::reverse(arr.begin(), arr.end());
    } else if (order == "random") {
        std::srand(0);
        std::random_shuffle(arr.begin(), arr.end());
    } else {
        std::cerr << "Invalid order. Use 'ascending', 'descending', or 'random'." << std::endl;
        return 1;
    }

    if (arraySize < 20) {
        std::cout << "Original array: \n";
        printArray(arr);
    }

    auto start = std::chrono::high_resolution_clock::now();
    quickSort(arr, 0, arraySize - 1, partitionFunc);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    if (arraySize < 20) {
        std::cout << "Sorted array: \n";
        printArray(arr);
    }

    std::cout << "Time taken for sorting: " << elapsed.count() << " seconds" << std::endl;
    return 0;
}