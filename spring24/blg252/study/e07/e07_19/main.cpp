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
	if (listObj.getPoint()) cout << "The list is not empty!" << endl;		// test: if the list is empty
	else cout << "The list is empty!" << endl;
	cout << "-----------------------" << endl;   // Seperator

	ColoredPoint  col_point1{ 10, 20, Color::Blue };	    // Object of ColoredPoint type
	listObj.append(&col_point1);							// Append a colored point to the list
	cout << "-----------------------" << endl;   // Seperator

	Point *ptrPoint1 = new Point {30, 40};						// Dynamic Point object 
	listObj.append(ptrPoint1);							        // Append a point to the list
	cout << "-----------------------" << endl;   // Seperator

	ColoredPoint  *ptrColPoint1 = new ColoredPoint{ 50, 60, Color::Red };	    // Dynamic Object of ColoredPoint type
	listObj.append(ptrColPoint1);							// Append a colored point to the list
	cout << "-----------------------" << endl;   // Seperator

	listObj.restartQurrent();								// qurrent pointer to the first node
	Point* local_ptrPoint;
	while (local_ptrPoint = listObj.getPoint())
	{
		cout << "X =" << local_ptrPoint->getX();
		cout << ", Y =" << local_ptrPoint->getY() << endl;
		listObj.next();
	}
	cout << "-----------------------" << endl;   // Seperator

	listObj.restartQurrent();								// qurrent pointer to the first node
	local_ptrPoint = listObj.getPoint();					// Get the pointer to the first point in the list
	local_ptrPoint->setX(0);								// OK. setX is a member of Point
	//local_ptrPoint->setColor(Color::Red);					// Error! setColor is not a member of Point

	delete ptrPoint1;
	delete ptrColPoint1;
	return 0;
}
