#include <iostream>
#include <stdio.h>
 using namespace std;

 int main() 
 {
    int x=5;
    float y=11.452;

    cout << "------SECTION 1------\n";
    int* x_address=&x;
    cout << *x_address << endl;
    cout << "x_address = "<< x_address << endl;
    cout << "y_address = " << &y << endl;

    int* x1 = new int;
    cout << "X1 = " << x1 << endl;
    cout << "*X1 = " << *x1 << endl;

    int* x2= new int{3};
    cout << "x2 = " << x2 << endl;
    cout << "*x2 = " << *x2 << endl;

    cout << "------SECTION 2------\n";
    int* x_pointer = &x;
    int &x_reference = x;
    cout << "x_pointer = " << x_pointer << " x_reference = " << x_reference << endl;
    cout << "&x_pointer = " << &x_pointer << " &x_reference = " << &x_reference << endl;

    {
        cout << "------SECTION 3------\n";
        int* arr = new int {14};
        cout << "arr = " << arr << " *arr= " << *arr << endl;
        int* array = new int[14];
        for(int i = 0; i<14; i++) 
        {
            //cout << &(array[i]) << " " << array[i] << endl;
            array[i] = i;
        }
        delete arr;
        cout << "arr deleted.\n";

        cout << "------SECTION 4------\n";
        int* pointer = array + 5;
        cout << (*pointer)++ << endl; 
        cout << endl;
        cout << *pointer++ << endl; 
        cout << endl;
        cout << *++pointer << endl; 
        cout << endl;
        cout << (*++pointer)++ << endl; 
        cout << endl;

        for(int i=0; i<14; i++)
        {
            cout << array[i] << endl;
        }

        delete[] array;
    }
    
    {
        int m=5;
        cout << "------SECTION 5------"<< endl;
        int array1[5][4];
        cout << "Array 1 elements\n";
        for(int i=0; i<m; i++) 
        {
            cout << &array1[i] << endl;
        }
    }
    
    {    
        cout << "-------SECTION 6------" << endl;
        int m = 5;
        int n=4;
        int** array2 = new int*[m];

        for(int i=0; i<m; i++) 
        {
            array2[i] = new int[n];
        }

        cout << "Array 2 elements\n";
        for(int i=0; i<m; i++) 
        {
            cout << &array2[i] << endl;
        }

        cout << "Size of an integer = "<< sizeof(int) << endl;
        cout << "Size of an int* = " << sizeof(int*) << endl;

        delete[] array2;
    }

    cout << "------SECTION 6------\n";
    delete x1;
    delete x2;
    return 0;
 }