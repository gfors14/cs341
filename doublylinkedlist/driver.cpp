#include <fstream>
#include <iostream>
#include <cstring>
#include "Node.h"
#include "LinkedNode.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"


int main()
{
	DoublyLinkedList test;
	int totalHopCount = 0;
	//test.insert(15);
	//test.insert(7);
//	test.insert(10);
	//test.printList();
	//std::cout << "Length: " << test.getLength() << std::endl;

	std::ifstream input;
	std::ifstream insert;
	
	
	
	input.open("sorted.txt");
	
	if(input.is_open())
	{
		int x = 0;
		while(!input.eof())
		{
			input >> x;
			test.insert(x);
			
		}
	//	test.printList();
	}
	else
	{
		std::cout << "Your file could not be opened. L!" << std::endl;
	}
	
	insert.open("inserts.txt");
	
	if(insert.is_open())
	{
		int y = 0;
		int z = 0;
		int hopcount1 = 0;
		int hopcount2 = 0;
		LinkedNode * temp = test.getHead();
		LinkedNode * temp2 = test.getTail();
	//	std::cout << "blah" << std::endl;
	//this is most scuffed code I have ever written. It works so allg.
	//basically what happens is it first tests a for loop for how many hops it would require to insert an item from the front. Then whenever that one is done it runs
	//another for loop to test it from the back. THen, it compares the hops, inserts based on less total hop count, and increments the hop cou nter
	
		while(!insert.eof())
		{
			hopcount1 = 0;
			hopcount2 = 0;
			insert >> y;
			temp = test.getHead();
			temp2 = test.getTail();
			//std::cout << "trying to insert " << y << std::endl;
			for(int i=0;i<test.getLength(); i++)
			{
				//std::cout << "blah2" << std::endl;
				z = temp->getValue();
				if(y > z)
				{
					hopcount1++;
					temp = temp->getNextLinkedNode();
					
				}
				else if(y <= z)
				{
					for(int i=0;i<test.getLength(); i++)
					{
						z = temp2->getValue();
						if(y < z)
						{
							hopcount2++;
							temp2 = temp2->getPrevLinkedNode();
						}
						else if (y >= z)
						{
							break;
						}
					}
					//std::cout << "needed " << hopcount1 << " hops " << std::endl;
					if(hopcount1 < hopcount2)
					{
						std::cout << "inserting " << y << " from the front" << std::endl;
						totalHopCount = totalHopCount + hopcount1;
						test.insertBeforeLinkedNode(temp, y);
					}
					else if(hopcount1 > hopcount2)
					{
						totalHopCount = totalHopCount + hopcount2;
						std::cout << "inserting " << y << " from the back" << std::endl;
						test.insertAfterLinkedNode(temp2, y);
					}
					else
					{
						totalHopCount = totalHopCount + hopcount1;
						std::cout << "same hops. inserting " << y <<" from front" << std::endl;
						test.insertBeforeLinkedNode(temp, y);
					}
				//	test.insertBeforeLinkedNode(temp, y);
				//	std::cout << "inserting " << y << std::endl;
					break;
				}
				else
				{
					/*
					std::cout << "needed " << hopcount1 << " hops " << std::endl;
					test.insertAfterLinkedNode(temp, y);
				//	test.printList();
					std::cout << "inserting " << y << std::endl;
					//temp = test.getHead();
					break; */
				}
			}
			
		}
		test.printList();
		test.remove(0);
		test.printList();
	//	std::cout << "WE HOPPED " << totalHopCount << "TIMES!!!!!!!!!!" << std::endl;
	}
	else
	{
		std::cout << "You need to take a serious introspective look into your life. Are you okay? I think you're past the option of medical help. Beyond saving. You need to be locked into a padded room for the rest of your life. Clinically insane individual. Laundry list of character flaws." << std::endl;
	}
	

	return 0;
}