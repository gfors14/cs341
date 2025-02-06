#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include "Node.h"

class linkedNode : private Node
{
public:
	LinkedNode(int data, LinkedNode * nextLinkedNode);
	LinkedNode * getNextLinkedNode();
	void setNextLinkedNode(LinkedNode * nextLinkedNode);
	bool hasNextLinkedNode();
private:
	LinkedNode * nextLinkedNode_;
	
	
	
}
#endif