#include "RedBlackTree.h"

RedBlackTree::RedBlackTree()
{
	
	
}

RedBlackTree::~RedBlackTree()
{
	
	
}

void RedBlackTree::insert(int data)
{
	TreeNode * newNode = new TreeNode(data);
	// newNode->setColor(1);
	TreeNode * root = nullptr;
	root = insertNode(getRoot(), newNode);
	balanceColor(root, newNode);
	setRoot(root);

	
	//TreeNode * newNode = newTreeNode(data);
	//newNode->setColor(1);
	//BinarySearchTree::setRoot(BinarySearchTree::insertNode(BinarySearchTree::getRoot(), newNode()));
	//TreeNode * root = BinarySearchTree::getRoot();
	//balanceColor(root, newNode);
	
}


	
void RedBlackTree::rotateLeft(TreeNode *& root, TreeNode *& newNode)
{
	TreeNode * rightChild = newNode->getRightChild();
	newNode->setRightChild(rightChild->getLeftChild());
	
	if(newNode->getRightChild() != nullptr)
	{
		newNode->getRightChild()->setParent(newNode);
	}
	
	rightChild->setParent(newNode->getParent());
	
	if(newNode->getParent() == nullptr)
	{
		setRoot(rightChild);
		root = rightChild;
	}
	else if(newNode == newNode->getParent()->getLeftChild())
	{
		newNode->getParent()->setLeftChild(rightChild);
	}
	else
	{
		newNode->getParent()->setRightChild(rightChild); //
	}

	rightChild->setLeftChild(newNode); //
	newNode->setParent(rightChild); //

}

void RedBlackTree::rotateRight(TreeNode *& root, TreeNode *& newNode)
{
	TreeNode * leftChild = newNode->getLeftChild();
	newNode->setLeftChild(leftChild->getRightChild());
	
	if(newNode->getLeftChild() != nullptr)
	{
		newNode->getLeftChild()->setParent(newNode);
	}
	
	leftChild->setParent(newNode->getParent());
	
	if(newNode->getParent() == nullptr)
	{
		setRoot(leftChild);
		root = leftChild;
	}
	else if(newNode == newNode->getParent()->getLeftChild())
	{
		newNode->getParent()->setLeftChild(leftChild);
	}
	else
	{
		newNode->getParent()->setRightChild(leftChild);
	}
	
	leftChild->setRightChild(newNode);
	newNode->setParent(leftChild);
}

void RedBlackTree::balanceColor(TreeNode *& root, TreeNode *& newNode)
{		
	TreeNode * parentNode = nullptr;
	TreeNode * grandParentNode = nullptr;
	
	while((newNode != root) && (newNode->getColor() != 'B') && (newNode->getParent()->getColor() == 'R'))
	{
		parentNode = newNode->getParent();
		grandParentNode = newNode->getParent()->getParent();
		
		if(parentNode == grandParentNode->getLeftChild())
		{
			TreeNode * uncleNode = grandParentNode->getRightChild();
			if(uncleNode != nullptr && uncleNode->getColor() == 'R')
			{
				grandParentNode->setColor('R');
				parentNode->setColor('B');
				uncleNode->setColor('B');
				newNode = grandParentNode;
			}
			else
			{
				if (newNode == parentNode->getRightChild())
				{
					rotateLeft(root, parentNode);
					
					newNode = parentNode;
					parentNode = newNode->getParent();
				}
				else
				{
				
				rotateRight(root, grandParentNode);
					
					//TreeNode * temp = nullptr;
				
				char temp = parentNode->getColor();
				parentNode->setColor(grandParentNode->getColor());
				grandParentNode->setColor(temp);
				}
				
			}
	}
	else
	{
		TreeNode * uncleNode = grandParentNode->getLeftChild();
		
		if((uncleNode != nullptr) && (uncleNode->getColor() == 'R'))
		{
			grandParentNode->setColor('R');
			parentNode->setColor('B');
			uncleNode->setColor('B');
			newNode = grandParentNode;
		
		}
		else
		{
			if(newNode == parentNode->getLeftChild())
			{
				rotateRight(root, parentNode);
				newNode = parentNode;
				parentNode = newNode->getParent();
			}
			else
			{
				rotateLeft(root, grandParentNode);
				//TreeNode * temp = nullptr;
				
			//rotateLeft(root, grandParentNode);
				
				char temp = parentNode->getColor();
				parentNode->setColor(grandParentNode->getColor());
				grandParentNode->setColor(temp);
				
			//newNode = parentNode;
				
				
				
				newNode = parentNode;
				
			}
		}
		
		
	}
	
	}
	root->setColor('B');
}



	void RedBlackTree::printRedNodes(TreeNode * root)
	{
		if(root == nullptr)
		{
			return;
		}
		else
		{
		printRedNodes(root->getLeftChild());
		if(root->getColor() == 'R')
		{
			std::cout << root->getValue() << std::endl;
		}
		printRedNodes(root->getRightChild());
		}
	}
	
	void RedBlackTree::printBlackNodes(TreeNode * root)
	{
		if(root == nullptr)
		{
			return;
		}
		else
		{
			if(root->getColor() == 'B')
			{
				std::cout << root->getValue() << std::endl;
			}
			
			printBlackNodes(root->getLeftChild());
			printBlackNodes(root->getRightChild());
		}
		
	}
	// Honor Pledge:
	//
	// I pledge that I have neither given nor received any help on this assignment.
	//
	// jclange & gfors



// print red nodes
/*
if(root == nullptr return 

else
	pritnrednodes root getlfeft child
if root color red 
out root value_compprint rednodes root get right child


//print black nodes
ir root null ptr return


else
	if root color = black
std;;cout root ->getvalue

pritnblacknodes (root get left child

pritn black nodes (root get right child

*/