void DoublyLinkedList::remove(int key)
{
	//is the key the same as the head of our list
	if(key == LinkedList::getHead()->getValue().getKey())
	{
		LinkedNode * currentHead = LinkedList::getHead();
		LinkedNode * nextNode = currentHead->getNextLinkedNode();
		
		LinkedList::setHead(nextNode);
		nextNode->setPrevLinkedNode(nullptr);
		
		currentHead->setNextLinkedNode(nullptr);
		delete currentHead;
		
	}
	else if(key == LinkedList::getTail()->getValue().getKey());
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