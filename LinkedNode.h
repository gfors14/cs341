#ifndef LINKEDNODE_H
#define LINKEDNODE_H
#include "Node.h"
#include <cstddef>
#include <iostream>
#include "HashEntry.h"


class LinkedNode : public Node //Inherits Node
{
	public:
		//Constructor
		LinkedNode(HashEntry data, LinkedNode * nextLinkedNode, LinkedNode * prevLinkedNode); 
		
		//Destructor
		virtual ~LinkedNode();
		
		//Gets location of nextLinkedNode
		LinkedNode * getNextLinkedNode(); 
		
		//Gets location of prevLinkedNode
		LinkedNode * getPrevLinkedNode(); 
		
		//Sets 
		void setNextLinkedNode(LinkedNode * nextLinkedNode); 
		
		void setPrevLinkedNode(LinkedNode * prevLinkedNode);
		
		bool hasNextLinkedNode(); //Checks if the nextLinkedNode is empty or not
		
		bool hasPrevLinkedNode(); //Checks if the prevLinkedNode is empty or not
		
	private:
		//Private attributes
		LinkedNode * nextLinkedNode_;
		LinkedNode * prevLinkedNode_;
		
	protected:
};

#endif

	// Honor Pledge:
	//
	// I pledge that I have neither given nor received any help on this assignment.
	//
	// jclange & gfors
