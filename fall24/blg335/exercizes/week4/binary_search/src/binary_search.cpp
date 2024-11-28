#include <iostream>
#include <string>
#include <vector>

using namespace std;

void merge(std::vector<int> &A, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for(int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for(int i = 0; i < n2; i++) {
        R[i] = A[mid + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i = i + 1;
        } else {
            A[k] = R[j];
            j = j + 1;
        }
        k++;
    }
    while(i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(std::vector<int> &A, int left, int right) {
    if(left < right) {
        int mid = left + (right - left)/ 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

int binarySearch (vector<int>& A, int l, int r, int key) {
    if(A.empty()) {
        cerr << "ERROR: Empty vector.\n";
        return 0;
    }

    int m = l + (r - l) / 2;
    if(A[m] == key) {
        return m;
    } else if(A[m] > key) {
        return binarySearch(A, l, m, key);
    } else {
        return binarySearch(A, m+1, r, key);
    }
}

int main() {
    // Example input
    std::vector<int> array = {5, 2, 9, 1, 5, 6, 11, 3, 26, 8};

    // Output unsorted array
    std::cout << "Unsorted array: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Call the insertion_sort function
    merge_sort(array, 0, array.size() - 1);

    // Output sorted array
    std::cout << "Sorted array: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int key = 0;

    std::cout << "Insert a value from array.\n";
    std::cin >> key;
    std::cout << "Find the key value " << key << " with binary search.\n";
    int position = binarySearch(array, 0, array.size() - 1, key);
    std::cout << "Key is the " << position + 1 << " of the array.\n";

    return 0;
}