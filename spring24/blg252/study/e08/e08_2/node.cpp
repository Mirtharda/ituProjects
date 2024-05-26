// node.cpp for e07_19
// Methods of the Node class

#include <iostream>
using std::cout;
using std::endl;
#include "node.h"

Node::Node(Point * in_point) : m_point{ in_point }, m_next{ nullptr }
{
	cout << "Node Constructor" << endl;
}

// Other methods if any .............