// pointlist.h for e07_19
// Definition of PointList class

// You don’t need to create your own classes for linked lists. std::list is already defined in the standard library.
// <list>
// We provide this example for educational purposes.

#pragma once

#include "node.h"

// *** The list consists of nodes
class PointList{
public:
	PointList();					// Default constructor creates an empty list
	~PointList();                   // Destructor deletes all nodes of the list
	void append(Point *);			// Add a point to the end of the list
	Point* getPoint() const;        // Return the current Point
	void next();					// Move the current pointer to the next node
	void restartQurrent() { m_current = m_head; } // Set the current pointer to the first node
private:
	Node* m_head{};					// The pointer to the first node in the list
	Node* m_current{};			    // The pointer to the current node in the list
};