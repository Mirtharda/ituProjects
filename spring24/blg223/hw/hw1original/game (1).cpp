#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iterator>


#include "../include/doublelinklist.h"
#include "../include/objects.h"



#include <stack>

#include <cstdlib> //rand(), srand()
#include <ctime>   //time()

#include <random> 
using namespace std;


int rand_chooser(){
    int choose = rand() % 6 + 1;

    return choose;
}

/*
int rand_chooser() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, 6);
    return distrib(gen);
}
*/
bool is_zero_state(int (&array)[1000][3], int room, int action, int object){     //array, room_id, action, object
    //cout << "loop is zero" << endl;
    int i = 0;
    while(i != 1000){
        if(array[i][0] == room && array[i][1] == action && array[i][2] == object){
            return true;
        }
        i++;
    }
    return false;
}

void add_to_zero_states(int (&array)[1000][3], int room, int action, int object){
    //cout << "loop add zero" << endl;
    if(is_zero_state(array, room, action, object)){
        return;
    }
    int add_place = 0;
    while(array[add_place][1] != 0){
        add_place++;
        if(add_place> 1000){
            cout << "max value exceed." <<endl;
            return;
        }
    }
    array[add_place][0] = room;
    array[add_place][1] = action;
    array[add_place][2] = object;
    return;
}
int main()
{   
    srand(time(nullptr));
    GameState first_state;
    first_state.create_init_state();
   
    stack<int> result;
    int zero_states[1000][3] = {0};

    int state = 0;
    int action = rand_chooser();
    int object = rand_chooser();
    state = first_state.advance(action, object);
    result.push(state);
    
    if(state == 0){
        add_to_zero_states(zero_states, first_state.room_id, action, object);
    }
    
    while(result.top() != 12){
        if(result.top() <= 0){
            result.pop();
        }

        action = rand_chooser();
        object = rand_chooser();
        
        while(is_zero_state(zero_states, first_state.room_id, action, object)){
            action = rand_chooser();
            object = rand_chooser();
            //cout << "loop" <<endl;
        }
        state = first_state.advance(action, object);
        result.push(state);
        if(state==0){
            add_to_zero_states(zero_states,first_state.room_id, action, object);
        }
    }
    cout << result.size();
    /*
    stack<int> the_way;
    while(!result.empty()){
        the_way.push(result.top());
    }

    while(!the_way.empty()){
        cout << the_way.top() <<" ";
        the_way.pop();
    }
    */
    return 0;
}

