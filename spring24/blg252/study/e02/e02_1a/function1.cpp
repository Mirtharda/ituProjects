// function1.cpp for the example e02_1a.zip
// contains definition of function1

#include <iostream>				// Standard header file for input and output
// import <iostream>;               // Since C++20 (module)
// import std;                      // Since C++23 (module)

// function1 increments the input parameter by 0.1
double function1(double input) {
	std::cout << "Function 1 is running \n";
	return input + 0.1;
}