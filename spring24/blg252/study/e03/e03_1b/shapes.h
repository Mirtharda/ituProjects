// shapes.h
// Headed file to declare the Point class
// As we have not yet covered all the subjects, this program has some shortcomings.
// We will improve it later
#pragma once

class Point{					// Declaration/Definition of the Point Class
public:
	void move(int, int);		// A function to move points
	void print();				// to print cordinates on the screen
	bool isOnZero();		   // is point on the zero point(0,0)?
private:
	int m_x{}, m_y{};		   // Properties: x and y coordinates. Initial values: 0,0
};