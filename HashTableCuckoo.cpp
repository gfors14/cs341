#include "HashTableCuckoo.h"

HashTableCuckoo::HashTableCuckoo(int size) //Constructor
{
	size_ = size;
	entry_ = new HashEntry[size];
	entry2_ = new HashEntry[size];
}

HashTableCuckoo::~HashTableCuckoo() //Destructor
{
	delete[] entry_;
	delete[] entry2_;
}

void HashTableCuckoo::insert(int key, int value)
{
	int key1 = 0;
	int key2 = 0;
	int tempKey = 0;
	int tempValue = 0;
	int tempKey2 = 0;
	int tempValue2 = 0;
	int count = 0;
	
	
	
	while(count <= size_)
	{
		key1 = key % size_;
		key2 = (key / size_) % size_;
		if(entry_[key1].getStatus() == OCCUPIED)
		{
			tempKey = entry_[key1].getKey();
			tempValue = entry_[key1].getValue();
		//	std::cout << tempKey << std::endl;
			entry_[key1].setKey(key);
			entry_[key1].setValue(value);
			key2 = (tempKey / size_) % size_;
			if(entry2_[key2].getStatus() == OCCUPIED)
			{
				tempKey2 = entry2_[key2].getKey();
				tempValue2 = entry2_[key2].getValue();
				entry2_[key2].setKey(tempKey);
				entry2_[key2].setValue(tempValue);
				key = tempKey2;
				value = tempValue2;
			}
			else
			{
				entry2_[key2].setStatus(OCCUPIED);
				entry2_[key2].setKey(tempKey);
				entry2_[key2].setValue(tempValue);
				
				return;
			}
			
		}
		else
		{
			entry_[key1].setStatus(OCCUPIED);
			entry_[key1].setKey(key);
			entry_[key1].setValue(value);
			return;
		}
		count++;
	
	}
	if(count>=size_)
	{
		std::cout << "There is a cycle. Rehash!" << std::endl;
	}
	
}

int HashTableCuckoo::search(int key)
{
	
	int key1 = 0;
	int key2 = 0;
	key1 = key % size_;
	key2 = (key / size_) % size_;
	
	if(entry_[key1].getKey() == key && entry_[key1].getStatus() == OCCUPIED)
	{
		std::cout << "Key: " << entry_[key1].getKey() << " Value: " << entry_[key1].getValue() << std::endl;
	}
	else if(entry2_[key2].getKey() == key && entry2_[key2].getStatus() == OCCUPIED)
	{
		std::cout << "Key: " << entry2_[key2].getKey() << " Value: " << entry2_[key2].getValue() << std::endl;
	}
	else
	{
		std::cout << "Key does not exist!" << std::endl;
	}
}

void HashTableCuckoo::remove(int key)
{
	int key1 = 0;
	int key2 = 0;
	key1 = key % size_;
	key2 = (key / size_) % size_;
	
	if(entry_[key1].getKey() == key)
	{
		entry_[key1].setStatus(REMOVED);
	}
	else if(entry2_[key2].getKey() == key)
	{
		entry2_[key2].setStatus(REMOVED);
	}
	else
	{
		std::cout << "Key does not exist!" << std::endl;
	}
	
	

}

void HashTableCuckoo::print()
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
	
	std::cout << "***********************************" << std::endl;
	for (int i = 0; i<size_; i++)
	{
		std::cout << "[" << i << "]: ";
		if (entry2_[i].getStatus() == OCCUPIED)
		{
			std::cout << entry2_[i].getKey();
		}
		std::cout << std::endl;

	}
	std::cout << "***********************************" << std::endl;
}