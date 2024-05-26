// colored_point.cpp for e07_19
// Methods of the ColoredPoint class

#include <iostream>
using std::cout;
using std::endl;
#include "colored_point.h"

ColoredPoint::ColoredPoint(int in_x, int in_y, Color in_color) : Point{ in_x,in_y }, m_color{ in_color }
{
	cout << "ColoredPoint Constructor" << endl;
}

// Other methods if any .............