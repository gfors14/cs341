#include <fstream>
#include <iostream>
#include <cstring>
#include "Node.h"
#include "TreeNode.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"


int main()
{
	//**PHASE 1**
	// std::ifstream infile;
	// infile.open("data.txt");
	//
	// if(infile.is_open())
	// {
	// 	std::cout << infile.rdbuf() << std::endl;
	// }
	// else
	// {
	// 	std::cout << "File is not open!" << std::endl;
	// }
	
	//**PHASE 2**
	std::ifstream infile;
	infile.open("data.txt");
	RedBlackTree RBT;
	if(infile.is_open()) //If data.txt is open:
	{
		int x = 0;
		while(!infile.eof()) //While not at end of file
		{
			infile >> x;
			std::cout << x << " ";
			RBT.insert(x); //insert x to list
			//RBT.balanceColor(RBT.getRoot(), x); 
		}
		
	}
	else
	{
		std::cout << "File is not open!" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Root: " << RBT.getRoot()->getData() << std::endl;
	std::cout << "Color: " << RBT.getRoot()->getColor() << std::endl;

	
	RBT.inorder(RBT.getRoot());
	std::cout << std::endl;
	RBT.postorder(RBT.getRoot());
	std::cout << std::endl;
	RBT.preorder(RBT.getRoot());
	
	RBT.printRedNodes(RBT.getRoot());
	RBT.printBlackNodes(RBT.getRoot());
	
	//use preorder to see if set p corretclt
	
	return 0;
}