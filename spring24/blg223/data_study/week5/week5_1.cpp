#include <iostream>

using namespace std;


template<typename T>
struct Node {
    private:
        T data;
        Node<T>* next = NULL;
        template<typename U> friend struct List;
        template<typename U> friend struct Queue;
    public:
        T getData() {return this->data;};
        void setData(T data) {this->data = data;};

        Node<T>* getNext() {return this->next;};
        void setNext(Node<T>* next) {this->next = next;};
};

template<typename T>
struct List {
    private:
        Node<T>* head = NULL;
        int elemcount = 0;
        template<typename U> friend struct Queue;
    public:
        Node<T>* getHead() {return this->head;};
        void addBack(T);
        void removeFront();
};

template<typename T>
void List<T>::addBack(T new_element) {
    cout << "-----------List.addBack()------------\n";

    Node<T>* newnode = new Node<T>;
    newnode->setData(new_element);
    newnode->setNext(NULL);

    Node<T>* last_node = this->head;
    if (last_node == NULL) {
        this->head = newnode;
    } else {
        while(last_node->getNext() != NULL) {
            last_node = last_node->getNext();
        }
        //we found the last_node(tail)
        //cout << "Our last node is: " << last_node->getData() << endl;
        last_node->setNext(newnode);
    }
        
    elemcount++;
}

template<typename T>
void List<T>::removeFront() {
    cout << "----------List.removeFront()----------\n";

    if (this->head == NULL) {
        cerr << "List is empty!" << endl;
        return;
    }
    Node<T>* to_delete = this->head;
    cout << "Element to delete: " << to_delete->getData() << endl;

    //this->head->setNext(to_delete->getNext());
    //cout << "New first element: " << this->head->getNext()->getData() << endl;

    this->head = this->head->getNext();
    if (this->head == NULL) {
        cout << "List is now empty!" << endl;
    } else {
        cout << "New first element: " << this->head->getData() << endl;
    }

    delete to_delete;
    elemcount--;
}

template<typename T>
struct Queue {
    private: 
        List<T> data;
        int elemcount = 0;
    public:
        void enqueue(T&);
        void dequeue();
        T& front();
};

template<typename T>
void Queue<T>::enqueue(T& new_element) {
    cout << "----------Queue.enqueue()---------\n";
    data.addBack(new_element);
    elemcount++;
    cout << "New element count: " << elemcount << endl;
}

template<typename T>
void Queue<T>::dequeue() {
    cout << "----------Queue.dequeue()---------\n";
    data.removeFront();
    elemcount--;
    cout << "New element count: " << elemcount << endl;
}


template<typename T>
T& Queue<T>::front() {
    return data.head->getData();
}


int main() {
    List<int> myList;

    cout << "--------MESSAGE 1--------\n";
    for(int i = 0; i < 7; i++) {
        myList.addBack(i);
    }
    myList.removeFront();

    Queue<int> myQueue;
    cout << "--------MESSAGE 2---------\n";
    for(int i = 0; i < 7; i++) {
        myQueue.enqueue(i);
        myQueue.front();
    }
    myQueue.dequeue();
    //myQueue.front();


    return 0;
}