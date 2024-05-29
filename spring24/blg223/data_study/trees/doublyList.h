#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next = NULL;
    Node* prev = NULL;
};

template <typename T>  
struct DoublyList {
    Node<T>* head = NULL;
    Node<T>* tail = NULL;

    int elemcount = 0;

    void addFront(T data) {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;

        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        elemcount++;
    } 

    void addBack(T data) {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;

        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        elemcount++;
    }

    void add(T data, int index) {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;

        if(index < 0 || index > elemcount) return;

        if(index == 0) {
            addFront(data);
            return;
        }

        if(index == elemcount) {
            addBack(data);
            return;
        }

        Node<T>* temp = head;
        for(int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;

        elemcount++;
    }

    void removeFront() {
        if(head == NULL) return;

        Node<T>* temp = head;
        head = head->next;

        if(head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }

        delete temp;
        elemcount--;
    }

    void removeBack() {
        if(head == NULL) return;

        Node<T>* temp = tail;
        tail = tail->prev;

        if(tail != NULL) {
            tail->next = NULL;
        } else {
            head = NULL;
        }
        delete temp;
        elemcount--;
    }

    void remove(int index) {
        Node<T>* temp = head;
        if(index < 0 || index >= elemcount) return;

        if(index == 0) {
            removeFront();
            return;
        }
        if(index == elemcount - 1) {
            removeBack();
            return;
        }

        for(int i = 0; i < index; i++) {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
        elemcount--;
    }
};
