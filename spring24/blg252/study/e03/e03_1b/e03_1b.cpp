// e03_1b.cpp
// Using the Point class defined in the header file

#include "shapes.h"			// Point class declaration
#include <iostream>	        // For cout

using std::cout;
using std::endl;

// Main function to test the Point class
int main()
{
	Point point1, point2;					// 2 object are defined: point1 and point2
	cout << "Cooridnates of the point1: ";
	point1.print();							// point1's coordinates to the screen
	point1.move(500, 50);			// point1 moves to (100,50)
	cout << "Cooridnates of the point1: ";
	point1.print();							// point1's coordinates to the screen
	cout << "Cooridnates of the point2: ";
	point2.print();							// point2's coordinates to the screen
	if (point1.isOnZero())					// is point1 on (0,0)?
		cout << "point1 is on zero point(0,0)" << endl;
	else
		cout << "point1 is NOT on zero point(0,0)" << endl;
	if (point2.isOnZero())					// is point2 on (0,0)?
		cout << "point2 is on zero point(0,0)" << endl;
	else
		cout << "point2 is NOT on zero point(0,0)" << endl;
	return 0;
}