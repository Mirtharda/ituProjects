#include <iostream>
#include <string>
#include <vector>

std::vector<int> insertion_sort(std::vector<int> &A, int n) {
    if(A.empty()) {
        return {};
    }
    for(int j = 1; j < n ; j++) {
        int key = A[j];
        int i = j - 1;

        while(i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        } 

        A[i + 1] = key;
    }
    return A;
}

int main() {
    // Example input
    std::vector<int> array = {5, 2, 9, 1, 5, 6};

    // Output unsorted array
    std::cout << "Unsorted array: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Call the insertion_sort function
    insertion_sort(array, array.size());

    // Output sorted array
    std::cout << "Sorted array: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}