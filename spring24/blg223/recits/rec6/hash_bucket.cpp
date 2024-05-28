#include <iostream>
#include <vector>

int hashFunction(int key, int size) {
    return key % size;
}

void erase(std::vector<int>& bucket, int key) {
    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (*it == key) {
            bucket.erase(it);
            break; 
        }
    }
}

int main() {
    const int tableSize = 10;

    std::vector<int> bucketArray[tableSize];

    int keys[] = {15, 22, 33, 41, 57, 42, 45};

    for (int key : keys) {
        int index = hashFunction(key, tableSize);
        bucketArray[index].push_back(key);
    }

    std::cout << "Hash Table:" << std::endl;
    for (int i = 0; i < tableSize; ++i) {
        std::cout << i << ": ";
        for (int key : bucketArray[i]) {
            std::cout << key << " ";
        }
        std::cout << std::endl;
    }

    erase(bucketArray[hashFunction(15, tableSize)], 15);
    erase(bucketArray[hashFunction(41, tableSize)], 41);

    std::cout << "\nHash Table After Erasing:" << std::endl;
    for (int i = 0; i < tableSize; ++i) {
        std::cout << i << ": ";
        for (int key : bucketArray[i]) {
            std::cout << key << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
