#include "DoublyLinkedList.h"


DoublyLinkedList::DoublyLinkedList() // : head_(nullptr), tail_(nullptr)
{
	
}

DoublyLinkedList::~DoublyLinkedList()
{

}

void DoublyLinkedList::printList()
{
	if(!isEmpty())
	{
		LinkedNode * ln = getHead();
		std::cout << ln->getValue().getKey();
		
		while(ln->hasNextLinkedNode())
		{
			ln = ln->getNextLinkedNode();
			std::cout << "<-->" << ln->getValue().getKey();
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "List is empty!" << std::endl;
	}
}

void DoublyLinkedList::insertAfterLinkedNode(LinkedNode * node, HashEntry data)
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

void DoublyLinkedList::insertBeforeLinkedNode(LinkedNode * node, HashEntry data)
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
	if(nullptr == LinkedList::getHead() -> getNextLinkedNode() && key == LinkedList::getHead() -> getValue().getKey())
	{
		setHead(nullptr);
	}
	else if(key == LinkedList::getHead()->getValue().getKey())
	{
		LinkedNode * currentHead = LinkedList::getHead();
		LinkedNode * nextNode = currentHead->getNextLinkedNode();
		
		LinkedList::setHead(nextNode);
		nextNode->setPrevLinkedNode(nullptr);
		
		currentHead->setNextLinkedNode(nullptr);
		delete currentHead;
		
	}
	else if(key == LinkedList::getTail()->getValue().getKey())
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
			
			if(currentNode->getValue().getKey() == key)
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