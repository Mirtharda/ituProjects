//VECTOR BASED STRUCTURE

#include <iostream>

using namespace std;

struct ArrayBST {
    private:
        int* tree;
        int capacity;
    public:
        void create(int);
        void insert(int);
        void print();

        void preorder(int);
};

void ArrayBST::create(int capacity) {
    this->capacity = capacity;
    tree = new int[capacity];

    for(int i=0; i<capacity; i++) {
        tree[i] = INT_MIN;
    }
}


void ArrayBST::insert(int value) {
    // If tree is empty
    if (tree[0] == INT_MIN) {
        tree[0] = value;
        return;
    }

    int index = 0;
    while (true) {
        // Left subtree
        if (value < tree[index]) {
            int leftChild = 2 * index + 1;
            if (leftChild >= capacity) {
                // Expand tree capacity
                int newCapacity = capacity * 2;
                int* newTree = new int[newCapacity];
                for (int i = 0; i < newCapacity; ++i) {
                    newTree[i] = INT_MIN;
                }
                // Copy existing elements to new tree
                for (int i = 0; i < capacity; ++i) {
                    newTree[i] = tree[i];
                }
                delete[] tree;
                tree = newTree;
                capacity = newCapacity;
            }

            if (tree[leftChild] == INT_MIN) {
                // Left child of index is empty
                tree[leftChild] = value;
                return;
            }
            // Left child of index exists
            index = leftChild;
        } else if (value > tree[index]) {
            int rightChild = 2 * index + 2;
            if (rightChild >= capacity) {
                // Expand tree capacity
                int newCapacity = capacity * 2;
                int* newTree = new int[newCapacity];
                for (int i = 0; i < newCapacity; ++i) {
                    newTree[i] = INT_MIN;
                }
                // Copy existing elements to new tree
                for (int i = 0; i < capacity; ++i) {
                    newTree[i] = tree[i];
                }
                delete[] tree;
                tree = newTree;
                capacity = newCapacity;
            }

            if (tree[rightChild] == INT_MIN) {
                // Right child of index is empty
                tree[rightChild] = value;
                return;
            }
            index = rightChild;
        } else {
            cerr << "The value already exists.\n";
            return;
        }
    }
}


void ArrayBST::print() {
    cout << "Preorder Traversal: ";
    preorder(0);    //start from root
    cout << endl;
}
void ArrayBST::preorder(int index) {
    if(index < capacity && tree[index] != INT_MIN) {
        cout << tree[index] << ", ";

        preorder(2 * index + 1);
        preorder(2 * index + 2);
    }
}

int main() {
    ArrayBST mytree;

    int capacity = 20;
    mytree.create(capacity);

    for(int i = 0; i < capacity; i++) {
        mytree.insert(i);
    }

    mytree.print();
    
    mytree.insert(3);

    mytree.print();


    return 0;
}