// node.h for e07_19
// Definition of Node class
#pragma once

#include "point.h"

// *** The Node class to build the nodes of the list
class Node{					
public:
	Node(Point *);
	Point* getPoint() const { return m_point; }		// Getter returns the point of the related node
	Node* getNext() const { return m_next; }		// Getter returns the pointer to the next node
	void setNext(Node * in_node) { m_next = in_node; }		// Setter modifies the next node
private:
	Point* m_point{};					// The pointer to the element of the list
	Node* m_next{};					   // Pointer to the next node
};