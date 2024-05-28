#include <iostream>

using namespace std;

const int LIMIT = 1000;

template<typename T>
struct a_stack {
    private: 
        T data[LIMIT];
        int elemcount = 0;
    public:
        void push(T& e);
        T pop();
        T& top();
};

template<typename T>
void a_stack<T>::push(T& new_element) {
    if(elemcount<LIMIT) {
        data[elemcount] = new_element;
        elemcount++;
    }
}

template<typename T>
T a_stack<T>::pop() {
    elemcount--;
    return data[elemcount];
}

template<typename T>
T& a_stack<T>::top() {
    return data[elemcount-1];
}
/*
template<typename T>
struct l_stack {
    private:
        List<T> data;
        int elemcount=0;
    public:
        void push(T& e);
        T pop();
        T& top();
};
*/


int main() {
    a_stack<int> myStack;
    for(int i = 5; i>0; i--) {
        myStack.push(i);
    }
    cout << myStack.pop() << endl;
    cout << myStack.pop() << endl;
    cout << myStack.pop() << endl;
    cout << myStack.top() << endl;
    cout << myStack.top() << endl;

    cout << "-----------Message 1----------\n";
    string math_exp[] = {"3", "6", "*", "3", "7", "/", "+"};
    a_stack<float> mystack2;

    for(int i=0; i<7; i++) {
        if(math_exp[i] != "*" && math_exp[i] != "/" && math_exp[i] != "+" && math_exp[i] != "-") {
            float value = stof(math_exp[i].c_str());
            mystack2.push(value);
        } else {
            float op1 = mystack2.pop();
            float op2 = mystack2.pop();
            float result;

            if(math_exp[i] == "/") {
                result = op2/op1;
            } else if(math_exp[i] == "+") {
                result = op2+op1;
            } else if(math_exp[i] == "*") {
                result = op2 * op1;
            } else if(math_exp[i] == "-") {
                result = op2 - op1;
            }
            mystack2.push(result);
        }
    }

    cout << mystack2.top() << endl;

    cout << "---------Hanoi Towers--------\n";
    a_stack<int> stacks[3];
    int diskcount = 3;

    for(int i=diskcount; i>0; i--) {
        stacks[0].push(i);
    }
/*
    while(1) {
        int src, dst;
        cout << "Source: ";
        cin >> src;

        cout << "Destination: ";
        cin>> dst;

        if(stacks[dst])
    }
*/ 
    return 0;
}