#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "LinkedNode.h"
#include <cstddef>
#include <iostream>

class LinkedList
{
	public:
		//Constructor
		LinkedList();
		
		//Destructor
		virtual ~LinkedList();
		
		bool isEmpty(); 
		
		int getLength(); 
		
		void insert(int element); 
		void insertLinkedNode(LinkedNode * node, int data);
		virtual void printList() = 0; 
		
		LinkedNode * getHead();
		void setHead(LinkedNode * node);
		LinkedNode * getTail();
		void setTail(LinkedNode * node);
		
	protected:
		
		// void insertLinkedNode(LinkedNode * newNode, int data);
	private:
		LinkedNode * head_;

		LinkedNode * tail_;
		
};

#endif