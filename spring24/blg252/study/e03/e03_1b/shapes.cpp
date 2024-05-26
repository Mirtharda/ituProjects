// shapes.cpp
// Implementation of the Point class
// Definitions of the member functions of the Point class

#include <iostream>	    // For cout
#include "shapes.h"		// The name of the header file, Point decleration


// ***** Bodies of Member Functions *****

// A function to move the points 
void Point::move(int new_x, int new_y)
{
	m_x = new_x;				// assigns new value to x coordinat
	m_y = new_y;				// assigns new value to y coordinat 
}

// To print the coordinates on the screen 
void Point::print()
{
	std::cout << "X= " << m_x << ", Y= " << m_y << std::endl;
}

// is the point on the zero point(0,0)
bool Point::isOnZero()
{
	return (m_x == 0) && (m_y == 0);
}