#ifndef QUICKSORT_PIVOTTING_H
#define QUICKSORT_PIVOTTING_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

// Function to swap two elements
void swap(int& a, int& b);

// Function to partition the array using the last element as pivot
int partitionLast(std::vector<int>& arr, int low, int high);

// Function to partition the array using a random pivot
int partitionRandom(std::vector<int>& arr, int low, int high);

// Function to find the median of three elements
int medianOfThree(std::vector<int>& arr, int low, int mid, int high);

// Partition function using median of three pivot selection
int partitionMedianOfThree(std::vector<int>& arr, int low, int high);

#endif // QUICKSORT_PIVOTTING_H
