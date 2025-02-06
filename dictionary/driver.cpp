#include <fstream>
#include <iostream>
#include <cstring>
#include "bitarray.h"
#include "dictionary.h"
#include "set.h"

int main()
{
	
	char q[] = "test";
	
	std::cout << std::endl;
	
	Dictionary dictionary;
	dictionary.initialize(q, strlen(q));
	
	//Set set(strlen(q));
	//set.initialize(q, strlen(q));
	//set.getData().print();
	
	std::cout << "Rank: " << dictionary.rank(32, 1) << std::endl;
	std::cout << "Rank Range (15-31): " << dictionary.rank_range(15, 31, 1) << std::endl;
	std::cout << "Select (5,1): " << dictionary.select(5, 1) << std::endl;
	std::cout << "Select Range (0,15,2,1): " << dictionary.select_range(0, 15, 2, 1) << std::endl;
	std::cout << std::endl;
	
}


	// Honor Pledge:
	//
	// I pledge that I have neither given nor received any help on this assignment.
	//
	// jclange & gfors