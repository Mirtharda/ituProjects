#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

//fill the list of worms function
//do the func for attacking worms

using namespace std;


template<typename T>
struct DoublyList;

template<typename T>
struct Node {
        T data;
        Node *next = NULL;
        Node *previous = NULL;
};

template<typename T>
struct DoublyList
{
        Node<T>* head = NULL;
        Node<T>* tail = NULL;
        int elemcount = 0;
        void addFront(T);
        void addBack(T);
        void add(T, int);
        void removeFront();
        void removeBack();
        void remove(int);
};

template<class T>
void DoublyList<T>::addBack(T new_element) {

    Node<T>* newnode = new Node<T>;
    newnode->data = new_element;
    newnode->previous = this->tail;

    if (this->tail != NULL)
        this->tail->next = newnode;

    this->tail = newnode;
    elemcount++;

    if(elemcount == 1)
        this->head = newnode;
}


template<class T>
void DoublyList<T>::removeBack() {

    if (this->tail != NULL)
    {
        Node<T>* old = this->tail;

        if (this->tail->previous != NULL)
            this->tail->previous->next = NULL;
        
        this->tail = this->tail->previous;
        delete old;
        elemcount--;
    }
}

template<class T>
void DoublyList<T>::removeFront() {

    if (this->head != NULL)
    {
        Node<T>* old = this->head;

        if (this->head->next != NULL)
            this->head->next->previous = NULL;
        
        this->head = this->head->next;
        delete old;
        elemcount--;
    }
}


template<class T>
void DoublyList<T>::addFront(T new_element) {

    Node<T>* newnode = new Node<T>;
    newnode->data = new_element;
    newnode->next = this->head;

    if (this->head != NULL)
        this->head->previous = newnode;

    this->head = newnode;
    elemcount++;

    if(elemcount == 1)
        this->tail = newnode;
}



template<class T>
void DoublyList<T>::add(T new_element, int position)
{
    if (position == 0)
    {
        addFront(new_element);
        return;
    }
    else if (position > elemcount)
        return;

    Node<T>* newnode = new Node<T>;
    newnode->data = new_element;
    Node<T>* prev_node = NULL;
    Node<T>* position_pointer = this->head;

    for(int index = 0; index < position ; index++)
    {
        prev_node = position_pointer;
        position_pointer = position_pointer->next;
    }

    prev_node->next = newnode;
    newnode->next = position_pointer;
    newnode->previous = prev_node;
    position_pointer->previous = newnode;

    elemcount++;
}

template<class T>
void DoublyList<T>::remove(int position)
{
    if (position == 0)
    {
        removeFront();
        return;
    }
    else if (position == elemcount-1)
    {
        removeBack();
        return;
    }
    else if(position >= elemcount)
        return;

    Node<T>* prev_node = NULL;
    Node<T>* position_pointer = this->head;

    for(int index = 0; index < position ; index++)
    {
        prev_node = position_pointer;
        position_pointer = position_pointer->next;
    }
    Node<T>* old = position_pointer;
    prev_node->next = position_pointer->next;

    if (position_pointer->next != NULL)
        position_pointer->next->previous = prev_node;
    delete old;
    elemcount--;
}

struct WormPart{
    int x,y;
};

DoublyList<WormPart*>* create_worm(char* filename)
{

    DoublyList<WormPart*>* worm = new DoublyList<WormPart*>;

    ifstream infile(filename);

    string line;
    while (true) {
        getline(infile, line);
        if (infile.eof()) {
            break;
        }

        int space_position = -1;

        for (int i=0; i<strlen(line.c_str()); i++)
        {
            if (line[i] == ' ')
                space_position = i;
        }

        int x = stoi(line.substr(0, space_position));
        int y = stoi(line.substr(space_position, strlen(line.c_str())));

        WormPart* new_part = new WormPart;
        new_part-> x = x;
        new_part-> y = y;

        worm->addFront(new_part);
    }
    
    return worm;
}

int main() {

    //just needed to fill the worms
    DoublyList<DoublyList<WormPart*>*> wormfield;

    char* filenames[4] = {"worm1.txt", "worm2.txt", "worm3.txt", "worm4.txt"};

    for (int i=0; i<4; i++)
    {
        DoublyList<WormPart*>* new_worm = create_worm(filenames[i]);    
        wormfield.addFront(new_worm);
    }

    while(1)
    {
        int option;
        cout << "------------------------------------" << endl;
        cout << "1- View the worms" << endl;
        cout << "2- Attack" << endl;
        cout << "3- Quit" << endl;
        cout << "------------------------------------" << endl;
        cout << "Please enter an action: ";
        cin >> option;

        //endless loop
        if (option == 1)
        {
            //clicked 1: return a worm list
            cout << "Worm List" << endl;

            Node<DoublyList<WormPart*>*>* ptr = wormfield.head;

            for(int i = 0; i < wormfield.elemcount; i++) {
                cout << "Worm " << i << " ";

                //when we out of that worm it will be deleted 
                //that is why we used pointer iterator
                for(Node<WormPart*>* wormnode_ptr = ptr->data->head; wormnode_ptr != NULL; wormnode_ptr->next) {
                    cout << "(" << wormnode_ptr->data->x << "," << wormnode_ptr->data->y << ")"; 
                    wormnode_ptr = wormnode_ptr->next;
                }
                cout << endl;
                
                ptr = ptr->next;

            }
        }
        else if (option == 2)
        {
            //clicked 2: attacked to somewhere
            cout << "Enter x y coordinates to attack" << endl;
        }
        else if (option == 3)
        {
            //clicked 3: ended the loop
            break;
        }
        else
        {
            cout << "Wrong Input!" << endl;
        }
    }
    

    

    

    
    return 0;
}
