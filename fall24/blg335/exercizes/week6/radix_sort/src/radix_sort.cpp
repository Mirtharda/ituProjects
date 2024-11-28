#include <iostream>
#include <vector>

int getMax(std::vector<int>& A) {
    if (A.empty()) {
        return -1;
    }
    int k = A[0];
    int n = A.size();
    for (int i = 1; i < n; i++) {
        if (A[i] > k) {
            k = A[i];
        }
    }
    return k;
}

void counting_sort(std::vector<int>& A, int exp) {
    int k = getMax(A); // Maximum value in the array
    int n = A.size();
    std::vector<int> C(k + 1, 0); // Frequency array
    std::vector<int> B(n, 0);     // Output array

    // Step 1: Count frequencies of each element
    for (int i = 0; i < n; i++) {
        C[(A[i] / exp) % 10]++;
    }

    // Step 2: Compute cumulative sums
    for (int i = 1; i < 10; i++) {
        C[i] += C[i - 1];
    }

    // Step 3: Build the sorted array
    for (int i = n - 1; i >= 0; i--) {
        B[C[(A[i] / exp) % 10] - 1] = A[i];
        C[(A[i] / exp) % 10]--;
    }

    // Step 4: Copy sorted elements back into the original array
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
}

void radix_sort(std::vector<int> &A) {
    int k = getMax(A);

    for(int exp = 1; k / exp > 0; exp *= 10) {
        counting_sort(A, exp);
    }
}

int main() {
    std::vector<int> array = {50, 2, 306, 708, 52};

    radix_sort(array);
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
