// e04_5.cpp
// The Copy Constructor

#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

class Point {								// Declaration of the Point Class with low-limits
public:
	Point(int, int, int, int);				// Constructor with to initialize all members
	Point(const Point&);					// Copy Constructor
	double distanceFromZero() const;		// const method calculates and returns the distance of a point from (0,0)
	void print() const;						// const method prints coordinates on the screen
	// Getters:
	int getX() const { return m_x; }		// Accessor for x coordinate
	int getY() const { return m_y; }		// Accessor for y coordinate
	// Setters:
	void setX(int);
	void setY(int);
	bool move(int, int);					// A non-constant method to move points

private:
	// Lower Limits of x and y
	const int MIN_x{};						// Zero initialization
	const int MIN_y{};
	int m_x{ MIN_x }, m_y{ MIN_y };			// x and y coordinates are initialized 
	mutable unsigned int m_printCount{};	// A mutable variable to count how many times a point object is printed
};

// ***** Bodies of Member Functions *****

// Constructor to initialize all members
Point::Point(int firstX, int firstY, int firstMINX, int firstMINY)
	  :MIN_x{firstMINX}, MIN_y{firstMINY}
{
	cout << "Constructor is called..." << endl;
	// It can call its methods
	setX(firstX); // Accepts only valid values 
	setY(firstY); // Accepts only valid values 
}


// Copy Constructor
Point::Point(const Point& originalPoint)
	:MIN_x{originalPoint.MIN_x}, MIN_y{originalPoint.MIN_y}, m_x{originalPoint.m_x}, m_y{originalPoint.m_y}
{
	cout << "The Copy constructor is called..." << endl;
}

/*
// The Copy Constructor may delagete to another constructor
Point::Point(const Point& originalPoint): Point { originalPoint.MIN_x, originalPoint.MIN_y, originalPoint.m_x, originalPoint.m_y}
{
	cout << "The Copy constructor is called..." << endl;
}
 */


// A const method calculates and returns the distance of a point from (0,0)
double Point::distanceFromZero() const {
	return std::sqrt(m_x * m_x + m_y * m_y);   // distance from (0,0)
}

// A const method to print the coordinates on the screen
// It also increments and prints the mutable printCount
void Point::print() const
{
	std::cout << "X= " << m_x << ", Y= " << m_y << std::endl;
	std::cout << "Print count= " << ++m_printCount << std::endl;  // increment and print the mutable printCount
}

// Setters
void Point::setX(int new_x) {
	if (new_x >= MIN_x) m_x = new_x;  // Accepts only valid values 
}
void Point::setY(int new_y) {
	if (new_y >= MIN_y) m_y = new_y;  // Accepts only valid values 
}

// A function to move the points 
// It checks the input values.
// If the values fall within the limits they are accepted, the point moves, and the function returns true.
// If the values are not within the limits, the point does not move, and the function returns false.
bool Point::move(int new_x, int new_y)
{
	if (new_x >= MIN_x &&  // if new_x is within the limits
		new_y >= MIN_y)    // if new_x is within the limits
	{
		m_x = new_x;						// assigns new value to x coordinate
		m_y = new_y;						// assigns new value to y coordinate 
		return true;
	}
	return false;						// new values are not accepted
}

// -------- Main Program -------------
int main()
{
	Point point1{-10, -10, 0, 20 };       // 1. point object
	cout << "Distance from Zero = " << point1.distanceFromZero() << endl;
	cout << "Printing the point1 object" << endl;
	point1.print();  
	cout << "Printing the point1 object again" << endl;
	point1.print();							// to increment the print count
	
	cout << "----------------------" << endl; // Seperator
	Point point2{ point1 };			// point 2 is a copy of point1
	cout << "Printing the point2 object" << endl;
	point2.print();
	
	cout << "----------------------" << endl; // Seperator
	point1.move(30, 40); // Now, point1 and point2 are diffrent.
	cout << "Printing the point1 object" << endl;
	point1.print();
	cout << "Printing the point2 object" << endl;
	point2.print();

	cout << "----------------------" << endl; // Seperator
	// Other notations to create copies of objects
	Point point3 = point2;
	Point point4(point1);
	return 0;
}