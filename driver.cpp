#include <fstream>
#include <iostream>
#include <cstring>
#include "Node.h"
#include "LinkedNode.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "HashTable.h"
#include "HashEntry.h"
#include "HashTableArray.h"
#include "HashTableChaining.h"
#include "HashTableCuckoo.h"

int main()
{
	//LINEAR/QUADRATIC:
	// HashTableArray HTA(QUADRATIC, 6);
	/*std::ifstream infile;
	infile.open("data.txt");

	if(infile.is_open()) //If data.txt is open:
	 {
		int key = 0;
		int value = 0;
		while(!infile.eof()) //While not at end of file
		{
	 		infile >> key >> value;
	 		HTA.insert(key, value);
	 	}
	 }
	 else //File can't be opened
	 {
	 	std::cout << "Your file could not be opened." << std::endl;
	 }
	 HTA.search(55);
	 HTA.print(); */

	//SEPARATE CHAINING
	// HashTableChaining HTC(6);

	// std::ifstream infile;
	// infile.open("data.txt");

	// if(infile.is_open()) //If data.txt is open:
	// {
	// 	int key = 0;
	// 	int value = 0;
	// 	while(!infile.eof()) //While not at end of file
	// 	{
	// 		infile >> key >> value;
	// 		HTC.insert(key, value);
	// 	}
	// }
	// else //File can't be opened
	// {
	// 	std::cout << "Your file could not be opened." << std::endl;
	// }
	// // std::cout << HTC.search(55) << std::endl;
	// HTC.remove(55);
	// HTC.print();

	//MENU
	int number = 0;
	int number2 = 0;
	int place = 10;
	int size = 0;
	int key = 0;
	std::cout << "Welcome to Blue IV's Can of Who Hash!" << std::endl;
	while(place != 0)
	{
		std::cout << "1) Linear Probing" << std::endl;
		std::cout << "2) Quadratic Probing" << std::endl;
		std::cout << "3) Separate Chaining" << std::endl;
		std::cout << "4) Cuckoo Hashing" << std::endl;
		std::cout << "5) Quit Program" << std::endl;
		std::cout << "Please enter your choice: ";
		std::cin >> number;
		
		if(number == 1)
		{
			//HashTableArray HTA(LINEAR, 6);
			std::cout << "Please enter the size of the Hash Table you wish to create: " << std::endl;
			std::cin >> size;
			HashTableArray HTA(LINEAR, size);
			
			std::ifstream infile;
			infile.open("data.txt");

			if(infile.is_open()) //If data.txt is open:
			 {
				int key = 0;
				int value = 0;
				while(!infile.eof()) //While not at end of file
				{
					infile >> key >> value;
					HTA.insert(key, value);
				}
				HTA.print();
			 }
			 else //File can't be opened
			 {
				std::cout << "Your file could not be opened." << std::endl;
				break;
			 }
			 
			 while(place != 0)
			 {
				 std::cout << "\n1) Search for entry " << std::endl;
				 std::cout << "2) Remove Entry  " << std::endl;
				 std::cout << "3) Print Hash Table " << std::endl;
				 std::cout << "4) Return to Main Menu " << std::endl;
				 std::cout << "\n Please enter your choice: " << std::endl;
				 
				 std::cin >> number2;
				 
				 if(number2 == 1)
				 {
					std::cout << "Search (please enter a key): " << std::endl;
					std::cin >> key;
					//HTA.search(key);
					if(HTA.search(key) == 1)
					{
						std::cout << "Invalid Key! Key " << key << " not found in table!" << std::endl;
					} 
				 }
				 else if(number2 == 2)
				 {
					std::cout << "Remove (please enter a key): " << std::endl;
					std::cin >> key;
					HTA.remove(key);
				 }
				 else if (number2 == 3)
				 {
					 HTA.print();
				 }
				 else if (number2 == 4)
				 {
					 break;
				 }
				 else
				 {
					 std::cout << "Invalid Number! Please enter a number 1-4!" << std::endl;
				 }
			 }
			
		}
		else if(number == 2)
		{
			std::cout << "Please enter the size of the Hash Table you wish to create: " << std::endl;
			std::cin >> size;
			HashTableArray HTA2(LINEAR, size);
			
			std::ifstream infile;
			infile.open("data.txt");

			if(infile.is_open()) //If data.txt is open:
			 {
				int key = 0;
				int value = 0;
				while(!infile.eof()) //While not at end of file
				{
					infile >> key >> value;
					HTA2.insert(key, value);
				}
				HTA2.print();
			 }
			 else //File can't be opened
			 {
				std::cout << "Your file could not be opened." << std::endl;
				break;
			 }
			 
			  while(place != 0)
			 {
				 std::cout << "\n1) Search for entry " << std::endl;
				 std::cout << "2) Remove Entry  " << std::endl;
				 std::cout << "3) Print Hash Table " << std::endl;
				 std::cout << "4) Return to Main Menu " << std::endl;
				 std::cout << "\n Please enter your choice: " << std::endl;
				 
				 std::cin >> number2;
				 
				 if(number2 == 1)
				 {
					std::cout << "Search (please enter a key): " << std::endl;
					std::cin >> key;
					//HTA.search(key);
					if(HTA2.search(key) == 1)
					{
						std::cout << "Invalid Key! Key " << key << " not found in table!" << std::endl;
					} 
				 }
				 else if(number2 == 2)
				 {
					std::cout << "Remove (please enter a key): " << std::endl;
					std::cin >> key;
					HTA2.remove(key);
				 }
				 else if (number2 == 3)
				 {
					 HTA2.print();
				 }
				 else if (number2 == 4)
				 {
					 break;
				 }
				 else
				 {
					 std::cout << "Invalid Number! Please enter a number 1-4!" << std::endl;
				 }
			 }
			 
		}
		else if(number == 3)
		{
			std::cout << "Please enter the size of the Hash Table you wish to create: " << std::endl;
			std::cin >> size;
			HashTableChaining HTC(size);
			
			std::ifstream infile;
			infile.open("data.txt");

			if(infile.is_open()) //If data.txt is open:
			 {
				int key = 0;
				int value = 0;
				while(!infile.eof()) //While not at end of file
				{
					infile >> key >> value;
					HTC.insert(key, value);
				}
				HTC.print();
			 }
			 else //File can't be opened
			 {
				std::cout << "Your file could not be opened." << std::endl;
				break;
			 }
			 
			  while(place != 0)
			 {
				 std::cout << "\n1) Search for entry " << std::endl;
				 std::cout << "2) Remove Entry  " << std::endl;
				 std::cout << "3) Print Hash Table " << std::endl;
				 std::cout << "4) Return to Main Menu " << std::endl;
				 std::cout << "\n Please enter your choice: " << std::endl;
				 
				 std::cin >> number2;
				 
				 if(number2 == 1)
				 {
					std::cout << "Search (please enter a key): " << std::endl;
					std::cin >> key;
					HTC.search(key);
				
				 }
				 else if(number2 == 2)
				 {
					std::cout << "Remove (please enter a key): " << std::endl;
					std::cin >> key;
					HTC.remove(key);
				 }
				 else if (number2 == 3)
				 {
					 HTC.print();
				 }
				 else if (number2 == 4)
				 {
					 break;
				 }
				 else
				 {
					 std::cout << "Invalid Number! Please enter a number 1-4!" << std::endl;
				 }
			 }
			 
		}
		else if(number == 4)
		{
			std::cout << "Please enter the size of the Hash Table you wish to create: " << std::endl;
			std::cin >> size;
			HashTableCuckoo HC(size);
			
			std::ifstream infile;
			infile.open("data.txt");

			if(infile.is_open()) //If data.txt is open:
			 {
				int key = 0;
				int value = 0;
				while(!infile.eof()) //While not at end of file
				{
					infile >> key >> value;
					HC.insert(key, value);
				}
				HC.print();
			 }
			 else //File can't be opened
			 {
				std::cout << "Your file could not be opened." << std::endl;
				break;
			 }
			 
			  while(place != 0)
			 {
				 std::cout << "\n1) Search for entry " << std::endl;
				 std::cout << "2) Remove Entry  " << std::endl;
				 std::cout << "3) Print Hash Table " << std::endl;
				 std::cout << "4) Return to Main Menu " << std::endl;
				 std::cout << "\n Please enter your choice: " << std::endl;
				 
				 std::cin >> number2;
				 
				 if(number2 == 1)
				 {
					std::cout << "Search (please enter a key): " << std::endl;
					std::cin >> key;
					HC.search(key);
				
				 }
				 else if(number2 == 2)
				 {
					std::cout << "Remove (please enter a key): " << std::endl;
					std::cin >> key;
					HC.remove(key);
				 }
				 else if (number2 == 3)
				 {
					 HC.print();
				 }
				 else if (number2 == 4)
				 {
					 break;
				 }
				 else
				 {
					 std::cout << "Invalid Number! Please enter a number 1-4!" << std::endl;
				 }
			
		} }
		else if(number == 5)
		{
			std::cout << "Thank you for using my program. Goodbye!" << std::endl;
			break;
		}
		else
		{
			std::cout << "Invalid choice!" << std::endl;
		}
	}

	return 0;
}