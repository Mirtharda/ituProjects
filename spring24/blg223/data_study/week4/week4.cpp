#include <iostream>
#include <stdio.h>

using namespace std;

template<typename T>
struct CircularList;

template<typename T>
struct Node {
    private:
        T data;
        Node* next = NULL;
        friend struct CircularList<T>;
};

template<typename T>
struct CircularList {
    private:
        Node<T>* cursor = NULL;
        //it can be thought like cursor is the end
        //cursor->next is the front
        int elemcount = 0;
    public:
        T& front();
        T& back();
        int length();
        void addEnd(T);
        void removeFront();
        void advance();
};

template<typename T>
T& CircularList<T>::front() {return cursor->next->data;}
template<typename T>
T& CircularList<T>::back() { return cursor->data;}
template<typename T>
void CircularList<T>::advance() {cursor = cursor->next;}



template<typename T>
void CircularList<T>::addEnd(T new_element) {
    Node<T>* newnode = new Node<T>;
    newnode->data = new_element;

    if(this->cursor == NULL) {
        newnode->next = newnode;
        cursor = newnode;
    } else {
        newnode->next = cursor->next;
        cursor->next = newnode;
    }
    elemcount++;
}

template<typename T>
void CircularList<T>::removeFront() {
    Node<T>* to_delete = cursor->next;

    if(to_delete == cursor) {
        //list only has cursor
        cursor = NULL;
    } else {
        cursor->next = to_delete->next;
    }
    delete to_delete;
    elemcount--;
}


int main() {

    CircularList<int> myList;
    cout << "----------Message 1----------" << endl;

/*    for(int i = 5; i>0; i--) {
        myList.addEnd(i);
    }

    myList.removeFront();

    Node<int>* ptr = myList.cursor;

    for(int i=0; i<10; i++) {
        cout << ptr->data << endl;
        ptr=ptr->next;
    }
*/
    cout << "----------Message 2----------" << endl;
    CircularList<int> list2;
    for(int i=5; i>0; i--) {
        list2.addEnd(i);
    }

    list2.removeFront();

    //Node<int>* ptr2 = list2.cursor;

    cout << "list2 items: \n";

    for(int i=0; i<10; i++) {
        cout << list2.front() << endl;
        list2.advance();
    }

    return 0;
}