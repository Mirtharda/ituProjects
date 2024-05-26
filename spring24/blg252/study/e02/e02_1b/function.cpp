// function.cpp for the example e02_1b.zip
// Module implementation
// contains definition of function1

module function;

// #include <iostream>				// Prior to C++20 header file for input and output
// import <iostream>;               // Since C++20 (module)
import std;                         // Since C++23 (module)

// function1 increments the input parameter by 0.1
double function1(double input) {
	std::cout << "Function 1 is running \n";
	return input + 0.1;
}