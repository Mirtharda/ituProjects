#include <iostream>

//SINGLE LINKED LIST

struct Node {
    int data;
    Node* next = NULL;
};

struct List {
    Node* head = NULL;
    int elemcount = 0;

    void addFront(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        elemcount++;
    }

    void removeFront() {
        if(head == NULL) return;

        Node* temp = head;
        head = head->next;

        delete temp;
        elemcount--;
    }

    void add(int data, int index) {
        if(index < 0 || index > elemcount) return;

        if(index == 0) {
            addFront(data);
            return;
        }

        Node* newNode = new Node;
        newNode->data = data;

        Node* temp = head;
        for(int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        elemcount++;
    }

    void remove(int index) {
        if(index < 0 || index > elemcount) return;

        if(index == 0) {
            removeFront();
            return;
        }

        Node* temp = head;
        for(int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;

        elemcount--;
    }
};