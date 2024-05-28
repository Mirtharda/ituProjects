#include <iostream>
#include <queue>
#include <cmath> // for floor function

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    TreeNode* root;

    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertUtil(root, value);
    }

 


    TreeNode* insertUtil(TreeNode* root, int value) {
        if (root == nullptr) {
            return new TreeNode(value);
        }

        if (value < root->val) {
            root->left = insertUtil(root->left, value);
        } else if (value > root->val) {
            root->right = insertUtil(root->right, value);
        }
        return root;
    }

    void findAverage() {
        if (root == nullptr) {
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            double sum = 0.0; 

            for (int i = 0; i < size; ++i) {
                TreeNode* current = q.front();
                q.pop();
                sum += current->val; 

                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }

            double average = sum / size; 
            cout << "Derinlik Ortalaması: " << average << endl;
        }
    }
};

int main() {
    BST bst;

    int arr[] = {10, 5, 15, 3, 7, 12, 20, 4,6,23};

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        bst.insert(arr[i]);
    }

    bst.findAverage();

    

    return 0;
}
