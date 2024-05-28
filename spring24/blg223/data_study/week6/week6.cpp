#include <iostream>

using namespace std;

template<typename T>
struct Node {
        T data;
        Node<T>* next = NULL;
};

template<typename T>
struct List {
        Node<T>* head = NULL;
        int elemcount = 0;
        void addFront(const T&);
        void removeFront();
        void add(const T&, int);
        void remove(int);
};

template<typename T>
void List<T>::addFront(const T& newdata) 
{
    Node<T>* newNode = new Node<T>;
    newNode->data = newdata;
    newNode->next = head;
    head = newNode;
    elemcount++;
}
template<typename T>
void List<T>::removeFront()
{
    if(this->head!=NULL) 
    {
        Node<T>* old = this->head;
        this->head = this->head->next;
        delete old;
        elemcount--;
    }
}
template<typename T>
void List<T>::add(const T& newdata, int position)
{
    if(position==0)
    {
        std::cout << "Node will be added front.\n";
        addFront(newdata);
        return;
    } else if(position>elemcount) {
        cerr << "Node position is not valid.\n";
        return;
    } else {
        Node<T>* newNode = new Node<T>;
        newNode->data = newdata;
        newNode->next = NULL;

        Node<T>* prev_node = NULL;
        Node<T>* position_node = this->head;

        for(int current = 0; current < position; current++)
        {
            prev_node = position_node;
            position_node = position_node->next;
        }

        prev_node->next = newNode;
        newNode->next = position_node;
        elemcount++;
    }

}
template<typename T>
void List<T>::remove(int position)
{
    if(position==0)
    {
        cout << "First element of list will be deleted.\n";
        removeFront();
        return;
    } else if(position>=elemcount) {
        cerr << "Invalid position to delete.\n";
        return;
    } else {
        Node<T>* prev_node = NULL;
        Node<T>* position_node = this->head;

        for(int current=0; current < position; current++) 
        {
            prev_node = position_node;
            position_node = position_node->next;
        }
        Node<T>* old = position_node;
        prev_node->next = position_node->next;
        delete old;

        elemcount--;
    }
} 

template<typename T>
struct TreeNode {
    T data;
    TreeNode<T>* parent;
    List<TreeNode<T>*> children;
};


template<typename T>
void printTree(TreeNode<T>* tree) {
    cout << tree->data << endl;

    for(Node<TreeNode<T>*>* ptr = tree->children.head; ptr != NULL; ptr = ptr->next) {
        printTree(ptr->data);
    }
}

int main() {
    TreeNode<int> head; //head is an actual object. not a pointer
    head.parent = NULL;
    head.data = 1;

    cout << "-------MESSAGE 1----------\n";
    for(int i=2; i<5; i++) {
        TreeNode<int>* newnode = new TreeNode<int>;
        newnode->data = i;
        newnode->parent = &head;

        head.children.addFront(newnode);
    }
    printTree(&head);

    cout << "---------MESSAGE 2---------\n";
    for(int i=5; i<7; i++) {
        TreeNode<int>* newnode = new TreeNode<int>;
        newnode->data = i;
        newnode->parent = head.children.head->data;
        head.children.head->data->children.addFront(newnode);
    }

    printTree(&head);



    return 0;
}