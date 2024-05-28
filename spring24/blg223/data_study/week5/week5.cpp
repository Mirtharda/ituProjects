//  Implement a Queue using array

#include <iostream>

using namespace std;

int const LIMIT = 1000;

template<typename T>
struct Queue {
    private:
        T data[LIMIT];
        int elemcount = 0;

    public:
        void enqueue(T);
        void dequeue();
        T& front();
};

template<typename T>
void Queue<T>::enqueue(T new_element) {
    //add new_element to the last
    if(elemcount < LIMIT) {
        data[elemcount] = new_element;
        cout << data[elemcount] << endl;
        elemcount++;
        return;
    }

    cerr << "Queue is full!!\n";
}

template<typename T>
void Queue<T>::dequeue() {
    //delete the first element
    cout << "-------dequeue will be used-------\n";
    cout << "The element that will be deleted: " << data[0] << endl;
    cout << "Last element before the delete: " << data[elemcount] << endl;

    for(int index = 0; index < elemcount; index++) {
        data[index] = data[index + 1];
        //cout << data[index] << endl;
    }
    elemcount--;
    /*
    for(int index = 0; index < elemcount; index++) {
        cout << data[index] << endl;
    }
    */
}

template<typename T>
T& Queue<T>::front() {
    cout << "The front element is: " << data[0] << endl;
    return data[0];
}


int main() {
    Queue<int> myQueue;
    for(int i = 0; i < 7; i++) {
        myQueue.enqueue(i);
    }
    myQueue.front();

    cout << "----------MESSAGE 1----------\n";
    myQueue.dequeue();

    cout << "----------MESSAGE 2----------\n";
    myQueue.front();

    return 0;
}