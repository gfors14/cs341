#include "DoublyLinkedList.h"


DoublyLinkedList::DoublyLinkedList() // : head_(nullptr), tail_(nullptr)
{
	
	
}

DoublyLinkedList::~DoublyLinkedList()
{
	//if(head_!=nullptr)
	//{
	//	delete head_;
	//}	
}
//we need to redefine printlist because it is a virtual function. WE are doing so so we can add the mysterious <--> instead of --> symbolziing that this is a double li nked list!!
void DoublyLinkedList::printList()
{
	if(!isEmpty())
	{
		LinkedNode * ln = getHead();
		std::cout << ln->getValue();
		
		while(ln->hasNextLinkedNode())
		{
			ln = ln->getNextLinkedNode();
			std::cout << "<-->" << ln->getValue();
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "List is empty!" << std::endl;
	}
}




//this should work correctly
void DoublyLinkedList::insertAfterLinkedNode(LinkedNode * node, int data)
{
	LinkedNode * newLinkedNode = new LinkedNode(data, nullptr, nullptr);
	
	if(!isEmpty())
	{
		if(node==getTail())
		{
			setTail(newLinkedNode);
			node->setNextLinkedNode(newLinkedNode);
			newLinkedNode->setPrevLinkedNode(node);
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
		setHead(newLinkedNode);
		setTail(newLinkedNode);
	}
	 
	
}

//this should work correctly
void DoublyLinkedList::insertBeforeLinkedNode(LinkedNode * node, int data)
{
	LinkedNode * newLinkedNode = new LinkedNode(data, nullptr, nullptr);
	
	if(!isEmpty())
	{
		if(node == getHead())
		{
			setHead(newLinkedNode);
			newLinkedNode->setNextLinkedNode(node);
			node->setPrevLinkedNode(newLinkedNode);
		}
		else
		{
			newLinkedNode->setNextLinkedNode(node);
			newLinkedNode->setPrevLinkedNode(node->getPrevLinkedNode());
			node->getPrevLinkedNode()->setNextLinkedNode(newLinkedNode);
			node->setPrevLinkedNode(newLinkedNode);
			
			//node->getNextLinkedNode()
		}
		
	}
	else
	{
		setHead(newLinkedNode);
		setTail(newLinkedNode);
	}
}

void DoublyLinkedList::remove(int key)
{
	//need a get key after get value in real thing
	
	//is the key the same as the head of our list
	if(key == LinkedList::getHead()->getValue())
	{
		LinkedNode * currentHead = LinkedList::getHead();
		LinkedNode * nextNode = currentHead->getNextLinkedNode();
		
		LinkedList::setHead(nextNode);
		nextNode->setPrevLinkedNode(nullptr);
		
		currentHead->setNextLinkedNode(nullptr);
		delete currentHead;
		
	}
	else if(key == LinkedList::getTail()->getValue())
	{
		LinkedNode * currentTail = LinkedList::getTail();
		LinkedNode * prevNode = currentTail->getPrevLinkedNode();
		
		LinkedList::setTail(prevNode);
		prevNode->setNextLinkedNode(nullptr);
		
		currentTail->setPrevLinkedNode(nullptr);
		delete currentTail;
		
	}
	else
	{
		LinkedNode * currentNode = LinkedList::getHead();
		bool isFound(false);
		
		while(currentNode->hasNextLinkedNode())
		{
			currentNode = currentNode->getNextLinkedNode();
			
			if(currentNode->getValue() == key)
			{
				isFound = true;
				break;
			}
		
		}
		
		if(isFound)
		{
			currentNode->getPrevLinkedNode()->setNextLinkedNode(currentNode->getNextLinkedNode());
			currentNode->getNextLinkedNode()->setPrevLinkedNode(currentNode->getPrevLinkedNode());
			
			currentNode->setPrevLinkedNode(nullptr);
			currentNode->setNextLinkedNode(nullptr);
			
			delete currentNode;
		}
		else
		{
			std::cout << "Key " << key << "not found!" << std::endl;
			
		}

	}
	
	

}








/*
LinkedNode * getHead_()
{
	return DoublyLinkedList::head_;
}

LinkedNode * getTail_()
{
	return DoublyLinkedList::tail_;
}
	
*/
