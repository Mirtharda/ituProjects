#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

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

    DoublyList<DoublyList<WormPart*>*> wormfield;

    char* filenames[4] = {"worms/worm1.txt", "worms/worm2.txt", "worms/worm3.txt", "worms/worm4.txt"};

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

        if (option == 1)
        {
            cout << "Worm List" << endl;

            Node<DoublyList<WormPart*>*>* ptr = wormfield.head;
            
            for (int i=0; i< wormfield.elemcount; i++)
            {
                cout << "Worm " << i << " ";

                for(Node<WormPart*>* wormnode_ptr = ptr->data->head; wormnode_ptr != NULL;
                 wormnode_ptr=wormnode_ptr->next)
                {
                    cout << "(" <<wormnode_ptr->data->x << "," << wormnode_ptr->data->y << ")";
                }
                cout << endl;


                ptr = ptr->next;           
            }
        }
        else if (option == 2)
        {
            cout << "Enter x y coordinates to attack" << endl;
            int x,y;
            cin >> x>>y;
            //Search for the node
            Node<DoublyList<WormPart*>*>* ptr = wormfield.head;
            bool found = 0;
            bool to_be_deleted = 0;
            int found_index = -1;
            for (int i=0; i< wormfield.elemcount; i++)
            {
                for(Node<WormPart*>* wormnode_ptr = ptr->data->head; wormnode_ptr != NULL; wormnode_ptr=wormnode_ptr->next)
                {
                    if (wormnode_ptr->data->x == x && wormnode_ptr->data->y == y)
                    {
                        found_index = i;
                        cout << "Worm " << found_index << " " << "Successfull attack!" <<endl;
                        found = 1;
                        if(wormnode_ptr == ptr->data->head)
                        {
                            ptr->data->removeFront();
                            ptr->data->removeFront();

                            if (ptr->data->elemcount == 0)
                                to_be_deleted = 1;
                            
                            break;
                        }
                        else if(wormnode_ptr == ptr->data->tail)
                        {
                            ptr->data->removeBack();
                            ptr->data->removeBack();

                            if (ptr->data->elemcount == 0)
                                to_be_deleted = 1;

                            break;
                        }
                        DoublyList<WormPart*>* firstworm = new DoublyList<WormPart*>;
                        DoublyList<WormPart*>* secondworm = new DoublyList<WormPart*>;

                        for(Node<WormPart*>* firstworm_pointer = ptr->data->head;firstworm_pointer->next != wormnode_ptr; firstworm_pointer=firstworm_pointer->next)
                        {
                                firstworm->addFront(firstworm_pointer->data);
                        }

                        for(Node<WormPart*>* secondworm_pointer = ptr->data->tail; secondworm_pointer->previous != wormnode_ptr; secondworm_pointer=secondworm_pointer->previous)
                        {
                                secondworm->addFront(secondworm_pointer->data);
                        }
                        if (firstworm->elemcount>0)
                            wormfield.addBack(firstworm);
                        if (secondworm->elemcount>0)
                            wormfield.addBack(secondworm);
                        to_be_deleted = 1;
                    }
                }
                if(found)
                    break;
                ptr = ptr->next;           
            }
            if(to_be_deleted)
                wormfield.remove(found_index);
        }
        else if (option == 3)
        {
            break;
        }
        else
        {
            cout << "Wrong Input!" << endl;
        }


    }

    return 0;
}
