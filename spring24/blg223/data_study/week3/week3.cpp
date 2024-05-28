#include <iostream>
#include <stdio.h>

using namespace std;

struct intNode 
{
    int data;
    intNode* next=NULL; 
};
struct intList
{
    intNode* head=NULL;
    int elemcount=0;
    void addFront(intNode*);
    void removeFront();
    void add(intNode*, int);
    void remove(int);
};

void intList::addFront(intNode* newNode) 
{
    newNode->next=this->head;
    this->head=newNode;
    elemcount++;
}
void intList::removeFront()
{
    if(this->head!=NULL) 
    {
        intNode* old = this->head;
        this->head = this->head->next;
        delete old;
        elemcount--;
    }
}
void intList::add(intNode* newNode, int position)
{
    if(position==0)
    {
        std::cout << "Node will be added front.";
        addFront(newNode);
        return;
    } else if(position>elemcount) {
        cerr << "Node position is not valid.";
    } else {
        intNode* prev_node = NULL;
        intNode* position_node = this->head;

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
void intList::remove(int position)
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
        intNode* prev_node = NULL;
        intNode* position_node = this->head;

        for(int current=0; current < position; current++) 
        {
            prev_node = position_node;
            position_node = position_node->next;
        }
        intNode* old = position_node;
        prev_node->next = position_node->next;
        delete old;

        elemcount--;
    }
} 
 
template<typename T>
struct Node
{
    T data;
    Node* next = NULL;
    Node* previous = NULL;
};
 
template<typename T>
struct doublyList
{
    Node<T>* head=NULL;
    Node<T>* tail=NULL;
    int elemcount=0;
    void addFront(T);
    void addBack(T);
    void add(T, int);
    void removeFront();
    void removeBack();
    void remove(int);
};

template<typename T>
void doublyList<T>::addFront(T new_element)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = new_element;
    newNode->next = this->head;

    if(this->head != NULL)
    {
        this->head->next = newNode;
    }
    this->head = newNode;
    elemcount++;

    if(elemcount==1)
    {
        this->tail=newNode;
    }
}

template<typename T>
void doublyList<T>::addBack(T new_element) 
{
    Node<T>* newNode = new Node<T>;
    newNode->data = new_element;
    newNode->previous = this->tail;

    if(this->tail != NULL)
    {
        this->tail->previos = newNode;
    }
    this->tail = newNode;
    elemcount++;

    if(elemcount == 1)
    {
        this->head = newNode;
    }
}

template<typename T>
void doublyList<T>::add(T new_element, int position) 
{
    if(position == 0)
    {
        addFront(new_element);
        return;
    } else if(position > elemcount){
        cerr << "Invalid position to be added!!" << endl;
        return;
    } else 
    {
        Node<T>* newnode = new Node<T>;
        newnode->data = new_element;
        Node<T>* prev_node = NULL;
        Node<T>* position_node = this->head;

        for(int current = 0; current < position; current++)
        {
            prev_node = position_node;
            position_node = position_node->next;
        }
        //found the place
        prev_node->next = newnode;
        newnode->next = position_node;
        position_node->previous = newnode;
        newnode->previous = prev_node;

        elemcount++;
    }
}

template<typename T>
void doublyList<T>::removeFront() 
{
    if(this->head != NULL) {
        Node<T>* old = this->head;

        if(this->head->next != NULL) {
            this->head->next->previous = NULL;
        }
        this->head = this->head->next;
        delete old;
        elemcount--;
    }
}

template<typename T>
void doublyList<T>::removeBack()
{
    if(this->tail != NULL) {
        Node<T>* old = this->tail;

        if(this->tail->previous != NULL) {
            this->tail->previous->next = NULL;
        }

        this->tail = this->tail->previous;
        delete old;
        elemcount--;
    }
}

template<typename T>
void doublyList<T>::remove(int position)
{
    if(position == 0) {
        removeFront();
        return;
    } else if(position == elemcount) {
        removeBack();
        return;
    } else if(position > elemcount) {
        cerr << "Invalid position to delete!!" << endl;
        return;
    } else {
        Node<T>* prev_node = NULL;
        Node<T>* position_node = this->head;

        for(int current = 0; current < position; current++)
        {
            prev_node = position_node;
            position_node = position_node->next;
        }
        Node<T>* old = position_node;
        prev_node->next = position_node->next;

        if(position_node->next != NULL) {
            position_node->next->previous = prev_node;
        }

        delete old;
        elemcount--; 
    }
}


int main()
{
    intList myList;

    for(int i=5; i>0; i--)
    {
        intNode* newNode = new intNode;
        newNode->data=i;
        myList.addFront(newNode);
    }

    int p=myList.elemcount;
    for(int i=20; i>4; i--)
    {        
        intNode* newNode = new intNode;
        newNode->data=i;
        myList.add(newNode, p);
        p++;
    }

    intNode* p_node = myList.head;
    cout << "MyList values: \n";
    while(p_node->next!=NULL)
    {
        cout << p_node->data << endl;
        p_node = p_node->next;
    }

    cout << "------------Message 1-----------\n";
    doublyList<int> list1;

    for(int i=0; i<10; i++) {
        Node<int>* n_node = new Node<int>;
        n_node->data = i;
        list1.addBack(n_node);
    }

    return 0;
}