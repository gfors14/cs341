#include "LinkedList.h"

LinkedList::LinkedList() : head_(nullptr), tail_(nullptr)
{
	// head_ = nullptr;
	// tail_ = nullptr;
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

void LinkedList::insert(int element)
{
	
	insertLinkedNode(tail_, element);
	/*LinkedNode * newLinkedNode = new LinkedNode(element, nullptr, nullptr);
	if(head_ == nullptr && tail_ == nullptr)
	{
		head_ = newLinkedNode;
	}
	else if(head_ != nullptr && tail_ == nullptr)
	{
		tail_ = newLinkedNode;
		head_->setNextLinkedNode(tail_);
		tail_->setPrevLinkedNode(head_);
	}
	else
	{
		newLinkedNode->setPrevLinkedNode(tail_);
		tail_->setNextLinkedNode(newLinkedNode);
		tail_ = newLinkedNode;
	}
	std::cout << "Inserting " << element << "..." << std::endl; */
}


void LinkedList::printList()
{
	if(!isEmpty())
	{
		LinkedNode * ln = head_;
		std::cout << ln->getValue();
		
		while(ln->hasNextLinkedNode())
		{
			ln = ln->getNextLinkedNode();
			std::cout << "-->" << ln->getValue();
		}
		
		std::cout << std::endl;
	}
	else
	{
		std::cout << "List is empty!" << std::endl;
	}
}


void LinkedList::insertLinkedNode(LinkedNode * node, int data)
{
	LinkedNode * newLinkedNode = new LinkedNode(data, nullptr, nullptr);
	
	if(!isEmpty())
	{
		
		if(node == tail_)
		{
			//insert at tail

			node->setNextLinkedNode(newLinkedNode);
			newLinkedNode->setPrevLinkedNode(node);
			tail_ = newLinkedNode;
			
		}
		else if(node == head_)
		{
			//hed
			
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


// void LinkedList::insertLinkedNode(LinkedNode * newNode, int data)
// {
// 	LinkedNode * newLinkedNode = new LinkedNode(data, nullptr);
//
// 	if(!isEmpty())
// 	{
// 		// tail_ = newNode;
// 		// newNode->setNextLinkedNode(tail_);
//
// 		// head_ = newNode;
// 		// newNode->setNextLinkedNode(tail_);
//
// 		// newNode->setNextLinkedNode(newNode->getNextLinkedNode());
// 		newNode->setNextLinkedNode(newLinkedNode);
// 	}
// 	else
// 	{
// 		head_ = newLinkedNode;
// 		tail_ = newLinkedNode;
// 	}
//
// }


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