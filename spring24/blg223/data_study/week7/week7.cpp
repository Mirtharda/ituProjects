//BINARY SEARCH TREE

#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;
};

template <typename T>
struct BinaryTree {
    Node<T>* root = NULL;

    Node<T>* insert(Node<T>* node, T data);
    Node<T>* remove(Node<T>* node, T key);  //why do we use key?

    bool search(Node<T>* node, T key);

    void inorder(Node<T>* node);
    void preorder(Node<T>* node);
    void postorder(Node<T>* node);

    Node<T>* minValueNode(Node<T>* node);
};

template <typename T>
Node<T>* BinaryTree<T>::insert(Node<T>* node, T data) {
    if(node == NULL) {
        node = new Node<T>;
        node->data = data;
        node->left = NULL;
        node->right = NULL;

        return node;
    } 

    if(data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }

    return node;
    
}

template<typename T>
Node<T>* BinaryTree<T>::remove(Node<T>* node, T key) {
    if(node == NULL) {
        return node;
    }

    if(key < node->data) {
        node->left = remove(node->left, key);
    } else if(key > node->data) {
        node->right = remove(node->right, key);
    } else {
        if(node->left == NULL) {
            Node<T>* temp = node->right;
            delete node;
            return temp;
        } else if(node->right == NULL) {
            Node<T>* temp = node->left;
            delete node;
            return temp;
        }
        Node<T>* temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
    }
    return node;
}


template<typename T>
bool BinaryTree<T>::search(Node<T>* node, T key) {
    if(node == NULL) {
        return false;
    }

    cout << "Current node: " << node->data << endl;
    if(node->data == key) {
        return true;
    } else if(key < node->data) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }
}

template<typename T>
void BinaryTree<T>::preorder(Node<T>* node) {
    if(node) {
        cout << node->data << ", ";
        preorder(node->left);
        preorder(node->right);
    }
}
template<typename T>
void BinaryTree<T>::inorder(Node<T>* node) {
    if(node) {
        inorder(node->left);
        cout << node->data << ", ";
        inorder(node->right);
    }
}
template<typename T>
void BinaryTree<T>::postorder(Node<T>* node) {
    if(node) {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << ", ";
    }
}


template<typename T>
Node<T>* BinaryTree<T>::minValueNode(Node<T>* node) {
    Node<T>* current = node;

    while(current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

int main() {

    BinaryTree<int> tree;
    tree.root = tree.insert(tree.root, 8);
    tree.insert(tree.root, 7);
    tree.insert(tree.root, 6);
    tree.insert(tree.root, 5);
    tree.insert(tree.root, 4);
    tree.insert(tree.root, 9);
    tree.insert(tree.root, 3);
    tree.insert(tree.root, 11);
    tree.insert(tree.root, 2);
    tree.insert(tree.root, 10);

    cout << "Preorder traversal: ";
    tree.preorder(tree.root);
    cout << endl;

    cout << "Inorer traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    if(tree.search(tree.root, 4) == true) {
        cout << "Found value 4\n";
    }
    


    return 0;
}