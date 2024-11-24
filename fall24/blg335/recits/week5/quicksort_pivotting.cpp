#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to partition the array using the last element as pivot
int partitionLast(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Function to partition the array using a random pivot
int partitionRandom(std::vector<int>& arr, int low, int high) {
    // Generate a random pivot index between low and high
    int pivotIndex = low + rand() % (high - low + 1);
    // Move the pivot element to the end
    swap(arr[pivotIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to find the median of three elements
int medianOfThree(std::vector<int>& arr, int low, int mid, int high) {
    if ((arr[low] > arr[mid]) != (arr[low] > arr[high]))
        return low;
    else if ((arr[mid] > arr[low]) != (arr[mid] > arr[high]))
        return mid;
    else
        return high;
}

// Partition function using median of three pivot selection
int partitionMedianOfThree(std::vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    int medianIndex = medianOfThree(arr, low, mid, high);
    swap(arr[medianIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
