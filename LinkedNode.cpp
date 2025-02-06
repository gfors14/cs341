#include "LinkedNode.h"

LinkedNode::LinkedNode(HashEntry data, LinkedNode * nextLinkedNode, LinkedNode * prevLinkedNode) : Node(data) //Constructor
{
	nextLinkedNode_ = nextLinkedNode;
}

LinkedNode::~LinkedNode() //Destructor
{
	delete nextLinkedNode_;
}

LinkedNode * LinkedNode::getNextLinkedNode() //Gets location of nextLinkedNode
{
	return nextLinkedNode_;
}

LinkedNode * LinkedNode::getPrevLinkedNode() //Gets location of prevLinkedNode
{
	return prevLinkedNode_;
}

void LinkedNode::setNextLinkedNode(LinkedNode * nextLinkedNode) //Sets nextLinkedNode
{
	nextLinkedNode_ = nextLinkedNode;
}

void LinkedNode::setPrevLinkedNode(LinkedNode * prevLinkedNode) //Sets prevLinkedNode
{
	prevLinkedNode_ = prevLinkedNode;
}

bool LinkedNode::hasNextLinkedNode() //Checks if the nextLinkedNode is empty or not
{
	if(nextLinkedNode_ != nullptr)
	{
		// std::cout << "Yes, it has a nextLinkedNode" << std::endl;
		return true;
	}
	else
	{
		// std::cout << "No, it does not have a nextLinkedNode" << std::endl;
		return false;
	}
}

bool LinkedNode::hasPrevLinkedNode() //Checks if the nextLinkedNode is empty or not
{
	if(prevLinkedNode_ != nullptr)
	{
		// std::cout << "Yes, it has a nextLinkedNode" << std::endl;
		return true;
	}
	else
	{
		// std::cout << "No, it does not have a nextLinkedNode" << std::endl;
		return false;
	}
}

	// Honor Pledge:
	//
	// I pledge that I have neither given nor received any help on this assignment.
	//
	// jclange & gfors