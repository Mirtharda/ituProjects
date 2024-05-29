#include <iostream>

template <typename T>
struct TreeNode {
    T data;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
};

template <typename T>
struct BinaryTree {
    TreeNode<T>* root = NULL;

    TreeNode<T>* insert(TreeNode<T>* root, T data) {
        if(root == NULL) {
            root = new TreeNode<T>;
            root->data = data;
            root->left = NULL;
            root->right = NULL;

            return root;
        }

        if(data < root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }

        return root;
    }

    TreeNode<T>* remove(TreeNode<T>* root, T key) {
        //key is the value we are looking for (to remove)

        if(root == NULL) return root

        if(key < root->data) {
            root->left = remove(root->left, key);
        } else if(key > root->data) {
            root->right = remove(root->right, key);
        } else {
            if(root->left == NULL) {
                TreeNode<T>* temp = root->right;
                delete root;
                delete temp;
            } else if(root->right == NULL) {
                TreeNode<T>* temp = root->left;
                delete root;
                delete temp;
            } else {
                TreeNode<T>* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = remove(root->right, temp->data);
            }
        }
        return root;
    }

    bool search(TreeNode<T>* root, T key) {
        if(root == NULL) return false;

        if(root->data == key) return true;

        if(key < root->data) {
            return search(root->left, key);
        } else {
            return search(root->right, key);
        }
    }

    TreeNode<T>* minValueNode(TreeNode<T>* root) {
        TreeNode<T>* current = root;

        while(current->left != NULL) {
            current = current->left;
        }

        return current;
    }

    int depth(TreeNode<T>* root) {
        if(root == NULL) return 0;

        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);

        return 1 + std::max(leftDepth, rightDepth);
    }

    int height(TreeNode<T>* root) {
        return depth(root) - 1;
    }

    void printTree(TreeNode<T>* root) {
        //inorder
        if(root == NULL) return;

        std::cout << root->data << " -> ";
        printTree(root->left);
        printTree(root->right);
    }

    void inorder(TreeNode<T>* root) {
        if(root == NULL) return;

        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
    void preorder(TreeNode<T>* root) {
        if(root == NULL) return;

        std::cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(TreeNode<T>* root) {
        if(root == NULL) return;

        postorder(root->left);
        postorder(root->right);
        std::cout << root->data << " ";
    }

};

