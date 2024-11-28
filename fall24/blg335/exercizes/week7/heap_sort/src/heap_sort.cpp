#include <vector>
#include <iostream>

void heapify(std::vector<int>& A, int n, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest;

    if(left < n && A[left]>A[i]) {
        largest = left;
    } else {
        largest = i;
    }

    if(right < n && A[right] > A[largest]) {
        largest = right;
    }

    if(largest != i) {
        //swap(largest, i)
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        heapify(A, n, largest);
    }
}

void build_heap(std::vector<int>& A) {
    int n = A.size();
    for(int i = n / 2 - 1; i >= 0; i--) {
        heapify(A, n, i);
    }
}

void heap_sort(std::vector<int>& A) {
    if(A.empty()) {
        return;
    }
    int n = A.size();

    build_heap(A);
    for(int i = n - 1; i >= 1; i--) {
        int temp = A[i];
        A[i] = A[0];
        A[0] = temp;

        n--;
        heapify(A, n, 0);
    }
}

int heap_extract_max(std::vector<int>& A) {
    int n = A.size() - 1;
    if(n < 0) {
        std::cerr << "ERROR: Heap underflow.\n";
        return -1;
    }

    int max = A[0];
    A[0] = A.back();
    A.pop_back();
    heapify(A, A.size(), 0);

    return max;
}

void heap_increase_key(std::vector<int>& A, int i, int key) {
    if(key < A[i]) {
        std::cerr << "ERROR: new key is smaller then current key.\n";
        return;
    }

    A[i] = key;
    while(i > 0 && A[(i-1) / 2] < A[i]) {
        int temp = A[i];
        A[i] = A[(i - 1) / 2];
        A[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    } 
}

int main() {
    std::vector<int> array = {2, 8, 14, 16, 4, 7, 1, 9, 10, 3};

    std::cout << "Original array:\n";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    heap_sort(array);
    std::cout << "Sorted array:\n";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> heap = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    int max = heap_extract_max(heap);
    std::cout << "Max number extracted: " << max << std::endl;

    std::cout << "Heap after extraction:\n";
    for (int num : heap) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    heap_increase_key(heap, 8, 15);
    std::cout << "Heap after key increase:\n";
    for (int num : heap) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
