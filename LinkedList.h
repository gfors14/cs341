#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "LinkedNode.h"
#include <cstddef>
#include <iostream>
#include "HashEntry.h"

class LinkedList
{
	public:
		//Constructor
		LinkedList();
		
		//Destructor
		virtual ~LinkedList();
		
		//Checks if empty
		bool isEmpty(); 
		
		//Gets length of the LinkedList
		int getLength(); 
		
		//Insert a node
		void insert(HashEntry element); 
		
		//Inserts a LinkedNode
		void insertLinkedNode(LinkedNode * node, HashEntry data);
		
		//Prints the list
		virtual void printList() = 0; 
		
		//Helper method to get head
		LinkedNode * getHead();
		
		//Helper method to change the head's LinkedNode
		void setHead(LinkedNode * node);
		
		//Helper method to get tail
		LinkedNode * getTail();
		
		//Helper method to change the tail's LinkedNode
		void setTail(LinkedNode * node);
		
	protected:
		
	private:
		//Private attributes
		LinkedNode * head_;
		LinkedNode * tail_;
		
};

#endif

	// Honor Pledge:
	//
	// I pledge that I have neither given nor received any help on this assignment.
	//
	// jclange & gfors
