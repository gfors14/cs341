#ifndef HASHTABLECUCKOO_H
#define HASHTABLECUCKOO_H

#include <iostream>
#include "HashEntry.h"
#include "HashTable.h"


class HashTableCuckoo : public HashTable
{
	public:
		HashTableCuckoo(int size);
		~HashTableCuckoo(); 
		void insert(int key, int value); 
		int search(int key); 
		void remove(int key); 
		void print(); 
		
		//Accessor Methods
		// int getSize();
		// void setSize(int size);
		// HashEntry * getEntry();
		// void setEntry(HashTable * entry);
		// HashEntry * getEntry2();
		// void setEntry2(HashTable * entry2);

	private:
		HashEntry * entry_; // Table I 
		HashEntry * entry2_; // Table II 
		int size_;  
	
};
#endif