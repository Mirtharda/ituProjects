//LINKED LIST

#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next = NULL;
};

struct List {
    Node* head = NULL;
    int elemcount = 0;

    void addFront(Node*);
    void removeFront();
};

void List::addFront(Node* newnode) {
    newnode->next = this->head;
    this->head = newnode;
    elemcount++;
}
void List::removeFront() {
    if(this->head != NULL) {
        Node* temp = this->head;
        this->head = this->head->next;
        delete temp;
        elemcount--;
    }
}


int main() {
    List mylist;

    for(int i=3; i>0; i--) {
        Node* newnode = new Node;
        newnode->data = i;
        mylist.addFront(newnode);
    }


    return 0;
}