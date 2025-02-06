driver.o: driver.cpp HashTableArray.o HashTableCuckoo.o HashTableChaining.o HashEntry.o Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o
	g++ driver.cpp HashTableArray.o HashTableCuckoo.o HashTableChaining.o HashEntry.o Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o -o blah

HashTableArray.o: HashTableArray.cpp HashTableArray.h
	g++ -c HashTableArray.cpp HashTableArray.h
	
HashTableCuckoo.o: HashTableCuckoo.cpp HashTableCuckoo.h
	g++ -c HashTableCuckoo.cpp HashTableCuckoo.h
	
HashTableChaining.o: HashTableChaining.cpp HashTableChaining.h
	g++ -c HashTableChaining.cpp HashTableChaining.h
	
HashEntry.o: HashEntry.cpp HashEntry.h
	g++ -c HashEntry.cpp HashEntry.h
	
Node.o: Node.cpp Node.h
	g++ -c Node.cpp Node.h
	
LinkedNode.o: LinkedNode.cpp LinkedNode.h
	g++ -c LinkedNode.cpp LinkedNode.h
	
LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp LinkedList.h
	
DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	g++ -c DoublyLinkedList.cpp DoublyLinkedList.h
	
clean:
	rm -f HashTableArray.o HashTableCuckoo.o HashTableChaining.o HashEntry.o Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o