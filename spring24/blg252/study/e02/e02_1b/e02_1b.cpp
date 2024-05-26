// e02_1b.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program uses modules instead of header files

import std;                     // Since C++23 (module) Standard Library
import function;                // Module that contains the function1
import ComplexT;                // Module that exports complexT

int main()
{
    ComplexT c1;                                        // A complex number c1 is defined
    double d1;			                                // A real number (double) is defined

    std::print ("Give a real number ");                 // Message to screen, cursor does NOT move to the new line
    std::cin >> d1;		                                // Read i and j from the keyboard

    c1.re = d1;                                         // We assign the value to the real part of the complex number
    c1.im = function1(d1);                              // We call the function1 and assign the output to the imaginary part of the complex number

    // The real and the imaginary parts of the complex number to the screen. Cursor goes to the new line
    std::println("Real part= {} and Imaginary part= {}", c1.re, c1.im); // There are two Replacement fields {}
    return 0;
}

