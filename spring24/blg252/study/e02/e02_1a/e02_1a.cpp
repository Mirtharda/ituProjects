// e02_1a.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program uses headers instead of modules 


#include "function1.h"    // Header file that contains the declaration of the function1
#include "complexT.h"     // Header file that contains the declaration of the complexT
#include <iostream>    // Standard header file for input and output (prior to C++20)
// import <iostream>;     // Since C++20 (module)
// import std;            // Since C++23 (module)

int main()
{
    ComplexT c1;                                        // A complex number c1 is defined
    double d1;			                                //A real number (double) is defined

    std::cout << "Give a real number ";                //Message to screen
    std::cin >> d1;		                                // Read i and j from the keyboard

    c1.re = d1;                                         // We assign the value to the real part of the complex number
    c1.im = function1(d1);                              // We call the function1 and assign the output to the imaginary part of the complex number

    std::cout << "Real part= " << c1.re << " and ";        // The real part of the complex number to the screen
    std::cout << "Imaginary part= " << c1.im << "\n";    // The imaginary part of the complex number to the screen
    return 0;
}