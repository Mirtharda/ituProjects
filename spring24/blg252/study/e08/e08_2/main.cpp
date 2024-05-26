// main.cpp for e07_19

#include <iostream>
using std::cout;
using std::endl;

#include "colored_point.h"
#include "pointlist.h"

// -------- Main Program -------------
int main()
{
	PointList listObj;										// Empty list
	listObj.printAll();

	ColoredPoint  col_point1{ 10, 20, Color::Blue };	    // Object of ColoredPoint type
	listObj.append(&col_point1);							// Append a colored point to the list

	Point *ptrPoint1 = new Point {30, 40};						// Dynamic Point object 
	listObj.append(ptrPoint1);							        // Append a point to the list

	ColoredPoint  *ptrColPoint1 = new ColoredPoint{ 50, 60, Color::Red };	    // Dynamic Object of ColoredPoint type
	listObj.append(ptrColPoint1);			// Append a colored point to the list

	cout << "Points in the list:" << endl;
	listObj.printAll();										// print all elements (points) in the list
	
	delete ptrPoint1;
	delete ptrColPoint1;
	return 0;
}
