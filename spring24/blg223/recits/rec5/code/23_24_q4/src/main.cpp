#include <iostream>
#include <vector>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode* arrayToTree(int arr[], int start, int end) {
    if (start > end) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(arr[start]);

    root->left = arrayToTree(arr, start * 2 + 1, end);

    root->right = arrayToTree(arr, start * 2 + 2, end);

    return root;
}

void preorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    std::cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

void postorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout << root->data << " ";
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    TreeNode* root = arrayToTree(arr, 0, size - 1);

    std::cout << "Preorder: ";
    preorderTraversal(root);
    std::cout << std::endl; 
    std::cout << "Inorder: ";
    inorderTraversal(root);
    std::cout << std::endl;
    std::cout << "Postorder: ";
    postorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
