#include "HashTableArray.h"

HashTableArray::HashTableArray(ProbingMethod pm, int size) //Constructor
{
	pm_ = pm;
	size_ = size;
	entry_ = new HashEntry[size];
}

HashTableArray::~HashTableArray() //Destructor
{
	delete[] entry_;
}

void HashTableArray::insert(int key, int value)
{
	int hash = key % size_;
	int count = (pm_ == QUADRATIC) ? (size_ * 2) : (size_);

	for (int i = 0; i<count; i++)
	{
		int modifier = (pm_ == QUADRATIC) ? (i * i) : (i);

		int index = (hash + modifier) % size_;
		if (entry_[index].getStatus() == OCCUPIED && entry_[index].getKey() == key)
		{
			entry_[index].setValue(value);
			return;
		}
		else if (entry_[index].getStatus() != OCCUPIED)
		{
			entry_[index].setKey(key);
			entry_[index].setValue(value);
			entry_[index].setStatus(OCCUPIED);
			return;
		}
	}
}

int HashTableArray::search(int key)
{
	//This function should return the value
	int hash = key % size_;
	int count = (pm_ == QUADRATIC) ? (size_ * 2) : (size_);

	for (int i = 0; i<count; i++)
	{
		int modifier = (pm_ == QUADRATIC) ? (i * i) : (i);

		int index = (hash + modifier) % size_;
		if (entry_[index].getStatus() == OCCUPIED && entry_[index].getKey() == key)
		{	
			std::cout << "Key: " << entry_[index].getKey() << std::endl;
			std::cout << "Value: " << entry_[index].getValue() << std::endl;
			
			return 0;
		}
	}
	
	return 1;
	// std::cout << "Invalid key! Key " << key << " not found in table!" << std::endl; DO THIS IN DRIVER
}

void HashTableArray::remove(int key)
{
	int hash = key % size_;
	int count = (pm_ == QUADRATIC) ? (size_ * 2) : (size_);
	int index;
	for (int i = 0; i<count; i++)
	{
		int modifier = (pm_ == QUADRATIC) ? (i * i) : (i);

		index = (hash + modifier) % size_;
		if (entry_[index].getStatus() == OCCUPIED && entry_[index].getKey() == key)
		{
			entry_[index].setStatus(REMOVED);
			return;
		}
	}
}

void HashTableArray::print()
{
	std::cout << "***********************************" << std::endl;
	for (int i = 0; i<size_; i++)
	{
		std::cout << "[" << i << "]: ";
		if (entry_[i].getStatus() == OCCUPIED)
		{
			std::cout << entry_[i].getKey();
		}
		std::cout << std::endl;

	}
	std::cout << "***********************************" << std::endl;
}