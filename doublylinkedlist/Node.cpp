#include "Node.h"

Node::Node(int data)
{
	data_ = data;
	
}

Node::~Node()
{
	
}

int Node::getValue()
{
	return data_;
	
}

void Node::setValue(int data)
{
	data_ = data;
}