//------------------------------
//Author: Selin Yılmaz
//Number: 150210100
//------------------------------

#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iterator>
#include "doublelinklist.h"
#include "objects.h"

using namespace std;
/*
template <typename T>
struct Stack {
    DoublyList<T> data;
    int size = data.elemcount;

    void push(T&);
    T pop();
    T& top();
};

template <typename T>
void Stack<T>::push(T& new_element) {
    data.addFront(new_element);
    data.elemcount++;
}

template <typename T>
T Stack<T>::pop() {
    T result = data.head->data;
    data.removeFront();
    data.elemcount--;
    return result;
}

template <typename T>
T& Stack<T>::top() {
    return data.head->data;
}
*/

int main()
{
    GameState first_state;
    first_state.create_init_state();

    DoublyList<int> result;
    int state = 0;
    int action = 1;
    int object1 = rand() % 6 + 1;
    int prevState = state;

    state = first_state.advance(action, object1);
    result.addFront(state); //push
    cout << "Select action: 1-Open 2-Look At 3-Pick Up 4- Misbehave 5- Talk To: ";
    cout << action << endl;
    cout << "Select object: ";
    cout << object1 << endl;        
    int effectID = first_state.advance(action, object1);
    std::cout << effectID << endl;    

    //if state is 12, game is won
    while(result.head->data != 12) {

        //there are 3 rooms

        //CELL
        if(first_state.room_id == 0) {
            for(action = 1; action <= 5; action++) {
                for(object1 = 0; object1 <= 6; object1++) {
                    cout << "Select action: 1-Open 2-Look At 3-Pick Up 4- Misbehave 5- Talk To: ";
                    cout << action << endl;
                    cout << "Select object: ";
                    cout << object1 << endl;


                    //0 does not effect anything and -1 means lose
                    //so they should not be in stack
                    if(result.head->data <= 0) {
                        result.removeFront(); //pop but not exactly
                    }
                    //cout << state << endl;
                    state = first_state.advance(action, object1);
                    result.addFront(state);
                    effectID = state;
                    //std::cout << effectID << endl;
                }
            }
        }
        //TOILET
        else if(first_state.room_id == 1) {
            for(action = 1; action <= 5; action++) {
                for(int object2 = 0; object2 <= 4; object2++) {
                    std::cout << "Select action: 1-Open 2-Look At 3-Pick Up 4- Misbehave 5- Talk To: ";
                    std::cout << action << endl;
                    std::cout << "Select object: ";
                    std::cout << object2 << endl;

                    //0 does not effect anything and -1 means lose
                    //so they should not be in stack
                    if(result.head->data <= 0) {
                        result.removeFront(); //pop but not exactly
                    }
                    prevState = result.head->data; //we will use it to avoid infinite loops

                    //we do not want to leave the toilet without toilet info
                    if(prevState != 11 && action == 1 && object2 == 4) {
                        object2++;
                        state = first_state.advance(action, object2);
                        //cout << state << endl;
                    } else if(prevState == 14 && action == 1 && object2 == 4) {
                        object2++;
                        state = first_state.advance(action, object2);
                        //cout << state << endl;
                    } else {
                        state = first_state.advance(action, object2);
                        //cout << state << endl;
                    }
                    result.addFront(state);
                    if(result.head->data <= 0) {
                        result.removeFront(); //pop but not exactly
                    }
                    //effectID = first_state.advance(action, object2);
                    //cout << effectID << endl;
                }
            }
        }
        //NEXT FLOOR
        else if(first_state.room_id == 2) {
            for(action = 1; action <= 6; action++) {
                for(int object3 = 0; object3 <= 2; object3++) {
                    if(result.head->data != 12) {
                        cout << "Select action: 1-Open 2-Look At 3-Pick Up 4- Misbehave 5- Talk To: ";
                        cout << action << endl;
                        cout << "Select object: ";
                        cout << object3 << endl;

                        //0 does not effect anything and -1 means lose
                        //so they should not be in stack
                        if(result.head->data <= 0) {
                            result.removeFront(); //pop but not exactly
                        }
                        
                        state = first_state.advance(action, object3);
                        result.addFront(state);
                        if(result.head->data <= 0) {
                            result.removeFront(); //pop but not exactly
                        }
                        //effectID = first_state.advance(action, object3);
                        //cout << effectID << endl;
                    }
                }
            }
        }
    }

    cout << "--------GAME IS WON!------------\n";
    cout << "Here are the steps:\n";
    while(result.elemcount != 0) {
        std::cout << result.tail->data << endl;
        result.removeBack();
    }


/*
    while (!first_state.lose && !first_state.win)
    {
        first_state.print_situation();
        int action, object;
        cout << "Select action: 1-Open 2-Look At 3-Pick Up 4- Misbehave 5- Talk To: ";
        cin >> action;
        cout << "Select object: ";
        cin >> object;
        int effectID = first_state.advance(action, object);//You may use effectID to check whether your last action changed something...
    }
*/

    return 0;

}
