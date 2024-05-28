//LECTURE 2
//Classes, Objects, Templates

#include <iostream>
#include <cstring>      //strcpy

using namespace std;

string weekdays[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
struct address 
{
    //char*     --> 8 byte
    //long int  --> 4 byte
    //address   --> 40 byte
    char* name;
    long int number;
    char* city;
    char* bloodtype[2];

    void set_name(char*);
    char* get_name();
};
//void address::set_name(char* newName) {}
//char* address::get_name() {}

int main()
{
    cout << "-------SECTION 1------\n";

    address myAddress;
    myAddress.name = new char[6];
    strcpy(myAddress.name, "Yusuf");
    myAddress.number = 1033;
    myAddress.city = new char[8];
    strcpy(myAddress.city, "Istanbul");
    myAddress.bloodtype[0] = new char[2];     //initialize how many memory we need.
    myAddress.bloodtype[1] = new char[1];       //must use "new", otherwise compiler error
    myAddress.bloodtype[0] = "AB";
    myAddress.bloodtype[1] = "-";

    cout << "------SECTION 2------\n";
    cout << sizeof(char*) << endl;
    cout << sizeof(long int) << endl;
    cout << sizeof(address) << endl;
    cout << sizeof(address*) << endl;

    cout << "------SECTION 3------\n";
    address* all_adresses = new address;
    all_adresses[0].name = new char[6];
    strcpy(all_adresses[0].name, "Yusuf");

    all_adresses[0].number = 1033; 

    cout << "-------SECTION 4------\n";
    cout << "My name = " << myAddress.get_name() << endl;
    myAddress.set_name("Selin");
    cout << "My name = " << myAddress.get_name() << endl;


    //delete myAddress;
    delete[] all_adresses;
    return 0;
}

void address::set_name(char* newName) 
{
    name = newName;
}
char* address::get_name() 
{
    return name;
}