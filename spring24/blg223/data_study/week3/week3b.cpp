//DOUBLY LINKED LIST

#include <iostream>

using namespace std;


struct Node {
    int data;
    Node* next = NULL;
    Node* previous = NULL;
};

struct DoublyList {
    Node* head = NULL;
    Node* tail = NULL;
    int elemcount = 0;

    void addFront(int);
    void addBack(int);
    void add(int, int);

    void removeFront();
    void removeBack();
    void remove(int);
};

void DoublyList::addFront(int newelement) {
    Node* newnode = new Node;
    newnode->data = newelement;
    newnode->next = this->head;

    if(this->head != NULL) {
        this->head->previous = newnode;
    } 
        this->head = newnode;
        elemcount++;

    if(elemcount == 1) {
        this->tail = newnode;
    }
}
void DoublyList::addBack(int newelement) {
    Node* newnode = new Node;
    newnode->data = newelement;
    newnode->previous = this->tail;

    if(this->tail != NULL) {
        this->tail->next = newnode;
    } 
        this->tail = newnode;
        elemcount++;
    
    if(elemcount == 1) {
        this->head = newnode;
    }
}
void DoublyList::add(int newelement, int position) {
    if(position == 0) {
        addFront(newelement);
        return;
    } else if(position > elemcount) {
        cerr << "Invalid position\n";
        return;
    }

    Node* newnode = new Node;
    newnode->data = newelement;
    Node* prevNode = NULL;
    Node* currentNode = this->head;

    for(int i = 0; i < position; i++) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    prevNode->next = newnode;
    newnode->next = currentNode;

    newnode->previous = prevNode;
    currentNode->previous = newnode;

    elemcount++;
}


void DoublyList::removeFront() {
    if(this->head != NULL) {
        Node* old = this->head;

        if(this->head->next != NULL) {
            this->head->next->previous = NULL;
        }
        this->head = this->head->next;
        delete old;
        elemcount--;
    }
}
void DoublyList::removeBack() {
    
}