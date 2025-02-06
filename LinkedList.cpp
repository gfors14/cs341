#include "LinkedList.h"

LinkedList::LinkedList() : head_(nullptr), tail_(nullptr)
{

}

LinkedList::~LinkedList()
{
	if(head_!=nullptr)
	{
		delete head_;
	}
}

bool LinkedList::isEmpty()
{
	if(head_ == nullptr)
	{
		// std::cout << "Yes, the LinkedList is empty" << std::endl;
		return true;
	}
	else
	{
		// std::cout << "No, the LinkedList is not empty" << std::endl;
		return false;
	}
}

int LinkedList::getLength()
{
	int count=0;
	if(!isEmpty())
	{
		count++;
		LinkedNode * temp = head_;
		
		while(temp->hasNextLinkedNode())
		{
			count++;
			temp = temp->getNextLinkedNode();
		}
	}
	return count;
}

void LinkedList::insert(HashEntry element)
{
	insertLinkedNode(tail_, element);
}


void LinkedList::printList()
{
	if(!isEmpty())
	{
		LinkedNode * ln = head_;
		std::cout << ln->getValue().getKey();
		
		while(ln->hasNextLinkedNode())
		{
			ln = ln->getNextLinkedNode();
			std::cout << "-->" << ln->getValue().getKey();
		}
		
		std::cout << std::endl;
	}
	else
	{
		std::cout << "List is empty!" << std::endl;
	}
}


void LinkedList::insertLinkedNode(LinkedNode * node, HashEntry data)
{
	LinkedNode * newLinkedNode = new LinkedNode(data, nullptr, nullptr);
	
	if(!isEmpty())
	{
		if(node == tail_)
		{
			//Insert at tail
			node->setNextLinkedNode(newLinkedNode);
			newLinkedNode->setPrevLinkedNode(node);
			tail_ = newLinkedNode;
			
		}
		else if(node == head_)
		{
			//Insert at head
			newLinkedNode->setNextLinkedNode(node);
			node->setPrevLinkedNode(newLinkedNode);
			head_ = newLinkedNode;
		}
		else
		{
			newLinkedNode->setNextLinkedNode(node->getNextLinkedNode());
			newLinkedNode->setPrevLinkedNode(node);
			node->getNextLinkedNode()->setPrevLinkedNode(newLinkedNode);
			node->setNextLinkedNode(newLinkedNode);
			
		}
	}
	else
	{
		head_ = newLinkedNode;
		tail_ = newLinkedNode;
	}
}

LinkedNode * LinkedList::getHead()
{
	return head_;
}
void LinkedList::setHead(LinkedNode * node)
{
	head_ = node;
}
LinkedNode * LinkedList::getTail()
{
	return tail_;
}
void LinkedList::setTail(LinkedNode * node)
{
	tail_ = node;
}
	// Honor Pledge:
	//
	// I pledge that I have neither given nor received any help on this assignment.
	//
	// jclange & gfors