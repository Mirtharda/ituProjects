#include <iostream>
#include <string>
#include <vector>

int partition(std::vector<int>& array, int start, int end) {
    int pivot = array[end];
    int i = start - 1;

    for(int j = start; j <= end; j++) {
        if(array[j] < pivot) {
            i++;
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
    i++;
    int temp = array[i];
    array[i] = array[end];
    array[end] = temp;

    return i;
}

void quick_sort(std::vector<int>& array, int start, int end) {
    if(end <= start) {
        return; //base_case
    }

    int pivot = partition(array, start, end);
    quick_sort(array, start, pivot - 1);
    quick_sort(array, pivot + 1, end);

}



int main() {
    std::vector<int> array = {8, 2, 5, 3, 9, 4, 7, 6, 1};

    std::cout << "Unsorted array ";
    for(int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    quick_sort(array, 0, array.size() - 1);

    std::cout << "Sorted array ";
    for(int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;    

    return 0;
}