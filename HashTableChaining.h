#ifndef HASHTABLECHAINING_H
#define HASHTABLECHAINING_H

#include <iostream>
#include "HashTable.h"
#include "DoublyLinkedList.h"

class HashTableChaining : public HashTable
{
	public:
		HashTableChaining(int size);
		~HashTableChaining();
		void insert(int key, int value); 
		int search(int key); 
		void remove(int key); 
		void print(); 
		
		//Accessor Methods
		// int getSize();
		// void setSize(int size);
		// DoublyLinkedList * getEntry();
		// void setEntry(HashTable * entry);

	private:
		DoublyLinkedList * entry_; 
		int size_;  
	
};
#endif