#include <iostream>
#include "doublyList.h"

template <typename T>
struct TreeNode {
    T data;
    TreeNode<T>* parent;
    DoublyList<TreeNode<T>*> children;
};

template <typename T>
void printTree(TreeNode<T>* root) {
    if(root == NULL) return;

    std::cout << root->data << " -> ";
    printTree(root->left);

    Node<TreeNode<T>>* temp = root->right->head;
    while(temp != NULL) {
        printTree(temp->data);
        temp = temp->next;
    }
}