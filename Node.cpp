#include "Node.h"


Node::Node(HashEntry data) //Constructor
{
	data_ = data;
}

Node::~Node() //Destructor
{
	
}

HashEntry Node::getValue() //Gets the Nodes Integer value.
{
	return data_;
	
}

void Node::setValue(HashEntry data) //Sets the value of the Node.
{
	data_ = data;
}

	// Honor Pledge:
	//
	// I pledge that I have neither given nor received any help on this assignment.
	//
	// jclange & gfors