#include "HashTableChaining.h"

HashTableChaining::HashTableChaining(int size) //Constructor
{
	size_ = size;
	//This is an array of DoublyLinkedLists. We do not want to use HashEntrys as the DoublyLinkedList is already made up of HashEntrys.
	//The difference between this and the HashTableArray is that there's no probing. It places it at that hash location no matter what.
	entry_ = new DoublyLinkedList[size];
}

HashTableChaining::~HashTableChaining() //Destructor
{
	delete[] entry_;
}

void HashTableChaining::insert(int key, int value)
{
	int hash = key % size_;
	bool foundKey = false;

	if (entry_[hash].isEmpty() == false)
	{
		LinkedNode * node = entry_[hash].getHead();

		while (true)
		{
			HashEntry he = node->getValue();

			if (he.getKey() == key)
			{
				he.setValue(value);
				foundKey = true;
			}

			if (node->hasNextLinkedNode())
			{
				node = node->getNextLinkedNode();
			}
			else
			{
				break;
			}
		}
	}

	if (foundKey == false)
	{
		HashEntry he;
		he.setKey(key);
		he.setValue(value);
		entry_[hash].insert(he);
		//entry_[hash].insertAfterLinkedNode(entry_[hash].getHead(), he);
	}
}

int HashTableChaining::search(int key)
{
	int hash = key % size_;

	if (entry_[hash].isEmpty() == false)
	{
		LinkedNode * node = entry_[hash].getHead();

		while (true)
		{
			HashEntry he = node->getValue();

			if (he.getKey() == key)
			{
				std::cout << "Key: " << he.getKey() << std::endl;
				std::cout << "Value: " << he.getValue() << std::endl;
				return 0;
			}

			if (node->hasNextLinkedNode())
			{
				node = node->getNextLinkedNode();
			}
			else
			{
				std::cout << "Invalid key! Key " << key << " not found in table!" << std::endl;
				break;
			}
		}
	}
	//std::cout << "Invalid key! Key " << key << " not found in table!" << std::endl; DO THIS IN DRIVER
}

void HashTableChaining::remove(int key) //This is the only method in this file that doesn't work yet. It seg faults if you try to remove certain keys idk why
{
	int hash = key % size_;

	bool foundKey = false;

	if (entry_[hash].isEmpty() == false)
	{
		LinkedNode * node = entry_[hash].getHead();

		while (true)
		{
			HashEntry he = node->getValue();

			if (he.getKey() == key)
			{
				foundKey = true;
			}

			if (node->hasNextLinkedNode())
			{
				node = node->getNextLinkedNode();
			}
			else
			{
				break;
			}
		}
	}
	if (foundKey == true)
	{
		entry_[hash].remove(key);
	}
}

void HashTableChaining::print()
{
	std::cout << "***********************************" << std::endl;
	for (int i = 0; i<size_; i++)
	{
		std::cout << "[" << i << "]: ";

		if (entry_[i].isEmpty() == false)
		{
			entry_[i].printList();
		}
		else
		{
			std::cout << std::endl;
		}
	}
	std::cout << "***********************************" << std::endl;
}