#ifndef HASHTABLEARRAY_H
#define HASHTABLEARRAY_H

#include <iostream>
#include "HashTable.h"
#include "HashEntry.h"

enum ProbingMethod {LINEAR, QUADRATIC};

class HashTableArray : public HashTable
{
	public:
		HashTableArray(ProbingMethod pm, int size);
		~HashTableArray();
		void insert(int key, int value); 
		int search(int key); 
		void remove(int key); 
		void print(); 
		
		//Accessor Methods
		// int getSize();
		// void setSize(int size);
		// HashEntry * getEntry();
		// void setEntry(HashEntry * entry);

	private:
		HashEntry * entry_; 
		int size_;  
		ProbingMethod pm_;
	
};
#endif