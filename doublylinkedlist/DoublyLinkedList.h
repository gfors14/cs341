#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "LinkedList.h"
#include "LinkedNode.h"

class DoublyLinkedList : public LinkedList
{
	
	public:
	DoublyLinkedList();
	~DoublyLinkedList();
	//void printList();
	void printList();
	void insertAfterLinkedNode(LinkedNode * node, int data);
	void insertBeforeLinkedNode(LinkedNode * node, int data);
	void remove(int key);
	//LinkedNode * getHead_();
//	LinkedNode * getTail_();
	//void setHead();
//	void setTail();
	private:
	//LinkedNode * head_;

	//LinkedNode * tail_;

	
	
	
	
};

#endif