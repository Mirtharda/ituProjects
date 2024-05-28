//BINARY TREE

#include <iostream>

using namespace std;

template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
};

template <typename T>
TreeNode<T>* createNode(T data, TreeNode<T>* parent) {
    //tree is not empty, there is a root

    TreeNode<T>* newnode = new TreeNode<T>;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = parent;

    return newnode;
}

template <typename T>
TreeNode<T>* createNode(T data) {
    //tree was empty

    TreeNode<T>* newtree = new TreeNode<T>;
    newtree->data = data;
    newtree->left = NULL;
    newtree->right = NULL;
    newtree->parent = NULL;

    return newtree;
}

//traversals
template <typename T>
void preorder(TreeNode<T>* ptr) {
    //cout << "-------------Preorder Traversal-----------\n";

    if(ptr) {
        cout << ptr->data << ", ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

template <typename T>
void inorder(TreeNode<T>* ptr) {
    //cout << "-----------------Inorder Traversal-------------\n";

    if(ptr) {
        inorder(ptr->left);
        cout << ptr->data << ", ";
        inorder(ptr->right);
    }
}

template <typename T>
void postorder(TreeNode<T>* ptr) {
    //cout << "-------------Postorder Traversal-------------\n";

    if(ptr) {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->data << ", ";
    }
}

template <typename T>
int depth(TreeNode<T>* tree) {
    if(tree->parent == NULL) { return 0; }
    else { return 1 + depth(tree->parent); }
}
template <typename T>
int height(TreeNode<T>* tree) {
    if(tree == NULL) { return 0; }
    else if(tree->left == NULL) { return height(tree->right) + 1; }
    else if(tree->right == NULL) { return height(tree->left) + 1; }
    else {
        return max(height(tree->left), height(tree->right)) + 1;
    }
}


int main() {
    TreeNode<int>* root = createNode(1);
    root->left = createNode(2, root);
    root->right = createNode(3, root);
    root->left->left = createNode(4, root->left);
    root->left->right = createNode(5, root->left);
    root->left->right->right = createNode(6, root->left->right);

    cout << root->left->right->parent->data << endl;

    cout << "preorder: ";
    preorder(root);
    cout << endl;
    cout << "inorder: ";
    inorder(root);
    cout << endl;
    cout << "Postorder: ";
    postorder(root);
    cout << endl;
    
    cout << "Depth: " << depth(root->left->right) << endl;
    cout << "Height: " << height(root) << endl;

    return 0;
}