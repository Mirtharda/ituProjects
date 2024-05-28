#include <iostream>
#include <queue>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* createBST(int arr[], int size) {
    if (size == 0) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);

    for (int i = 1; i < size; ++i) {
        TreeNode* current = root;
        while (true) {
            if (arr[i] < current->val) {
                if (current->left == nullptr) {
                    current->left = new TreeNode(arr[i]);
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == nullptr) {
                    current->right = new TreeNode(arr[i]);
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }

    return root;
}

void mirror(TreeNode* root) {
    if (root == nullptr) return;

    mirror(root->left);
    mirror(root->right);

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void bfs(TreeNode* root) {
    if (root == nullptr) {
        cout << "     " << endl ;
        return;
    }
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();
            if (current != nullptr) {
                cout << current->val << " ";
                q.push(current->left);
                q.push(current->right);
            }else{
                cout << "   ";
            }
        }
        cout << endl;
    }
}

int main() {
    int arr[] = {5, 3, 7, 1, 4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    TreeNode* root = createBST(arr, n);

    mirror(root);

    bfs(root);

    return 0;
}
