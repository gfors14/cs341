#include <fstream>
#include <iostream>
#include <cstring>
#include "bitarray.h"
#include "dictionary.h"
#include "set.h"

int main()
{

	char q[] = "test";
	char p[] = "ryan";
	
	Set set(strlen(q));
	Set set2(strlen(p));
	
	set.initialize(q, strlen(q));
	set2.initialize(p, strlen(p));
	
	set.getData().print();
	set2.getData().print();
	
	std::cout << std::endl;
	std::cout << "Cardinality: " << set.getCardinality() << std::endl;
	std::cout << std::endl;
	
	std::cout << "Set Union (A U B): " << std::endl;
	set.setUnion(set2);
	set.getData().print();
	std::cout << std::endl;
	
	set.initialize(q, strlen(q));
	set2.initialize(p, strlen(p));
	
	std::cout << "Set Intersection (A X B): " << std::endl;
	set.setIntersection(set2);
	set.getData().print();
	std::cout << std::endl;
	
}


	// Honor Pledge:
	//
	// I pledge that I have neither given nor received any help on this assignment.
	//
	// jclange & gfors