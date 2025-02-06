driver.o: driver.cpp Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o
	g++ driver.cpp Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o -o blah

Node.o: Node.cpp Node.h
	g++ -c Node.cpp Node.h
	
LinkedNode.o: LinkedNode.cpp LinkedNode.h
	g++ -c LinkedNode.cpp LinkedNode.h
	
LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp LinkedList.h
	
DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	g++ -c DoublyLinkedList.cpp DoublyLinkedList.h
	
clean:
	rm -f Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o
	
	
