// pointlist.cpp for e07_19
// Methods of the List class

// You don’t need to create your own classes for linked lists. std::list is already defined in the standard library.
// <list>
// We provide this example for educational purposes.

#include <iostream>
using std::cout;
using std::endl;
#include "pointlist.h"

// Default constructor creates an empty list
PointList::PointList() : m_head{ nullptr }, m_current{ nullptr }
{
	cout << "PointList Constructor" << endl;
}

// Add a point to the end of the list
void PointList::append(Point* in_point)
{			
	Node *new_node = new Node{ in_point };			// A new node that point to the given point object
	Node *previous, *current;						// Pointers to move in the list
	if (m_head)        // if the list is not empty
	{
		previous = m_head;
		current = m_head->getNext();
		while (current)             // searh for the end of the list
		{
			previous = current;
			current = current->getNext();
		}
		previous->setNext(new_node);			// Put the new node to the end of the list
	}
	else             // if the list is empty
	{
		m_head = new_node;						// The new node is the first element in the list.
		m_current = m_head;		
		
	}
}

// Returns the current Point
Point* PointList::getPoint() const {
	if (m_current) return m_current->getPoint();
	else return nullptr;
}

// Moves the current pointer to the next node
void PointList::next()
{
	if (m_current) m_current = m_current->getNext();
}

// Destructor
// deletes all nodes of the list
PointList::~PointList()
{
	Node* temp;
	while (m_head)        // if the list is not empty
	{
		temp = m_head;
		m_head = m_head->getNext();
		delete temp;
	}
}
// Other methods if any .............