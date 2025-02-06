#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
	root_ = nullptr;
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree & tree)
{
	root_ = tree.getRoot();
}

BinarySearchTree::~BinarySearchTree()
{
	if (root_ != nullptr)
	{
		delete root_;
	}
}

TreeNode * BinarySearchTree::getRoot() const
{
	return root_;
}

void BinarySearchTree::insert(int data)
{
	TreeNode * newNode = new TreeNode(data);
	
	root_ = insertNode(root_, newNode);
}

TreeNode * BinarySearchTree::insertNode(TreeNode * root, TreeNode * node)
{
	// If the BST is empty - go ahead and make the node the root.
	if (root == nullptr)
	{
		node->setColor(1);
		return node;
		
	}
	else
	{
		// Determine which subtree to insert the node into...
		if (node->getData() < root->getData()) 
		{ 
			// Left Subtree
			node->setColor(0);
			root->setLeftChild(insertNode(root->getLeftChild(), node)); 
			root->getLeftChild()->setParent(root); 
			/*
			if(root->getParent() != nullptr)
			{
				root->getLeftChild()->setGrandpa(root->getParent());
				
				if(root->getParent()->getLeftChild() == root)
				{
					if(root->getParent()->getRightChild() != nullptr)
					{
						root->getLeftChild()->setUncle(root->getParent()->getRightChild());
					}
					else
					{
					
					}
				}
				else
				{
					if(root->getParent()->getRightChild() != nullptr)
					{
						root->getLeftChild()->setUncle(root->getParent()->getLeftChild());
					}
					else
					{
					
					}
				}
			}
			else
			{
				
			}

			*/
		} 
		else 
		{ 
			// Right Subtree
			node->setColor(0);
			root->setRightChild(insertNode(root->getRightChild(), node)); 
			root->getRightChild()->setParent(root); 
			/*
			root->getRightChild()->setGrandpa(root->getParent());
			
			if(root->getParent()->getLeftChild() == root)
			{
				root->getRightChild()->setUncle(root->getParent()->getRightChild());
			}
			else
			{
				root->getRightChild()->setUncle(root->getParent()->getLeftChild());
			} */
		}
		
		return root;
	}	
}

void BinarySearchTree::setRoot(TreeNode * root)
{
	root_ = root;
}

//left subtree, root, right subtree

void BinarySearchTree::inorder(TreeNode * root)
{
	if(root == nullptr)
	{
		return;
	}
	
	inorder(root->getLeftChild());
	std::cout << root->getData() << " ";
	inorder(root->getRightChild());
	
	
}

//root, left subtree, right subtree

void BinarySearchTree::preorder(TreeNode * root)
{
	
	if(root == nullptr)
	{
		return;
	}
	std::cout << root->getData() << " ";
	preorder(root->getLeftChild());
	preorder(root->getRightChild());
	
	
}


//left subtree, right subtree, root

void BinarySearchTree::postorder(TreeNode * root)
{
	if(root == nullptr)
	{
		return;
	}
	
	postorder(root->getLeftChild());
	postorder(root->getRightChild());
	std::cout << root->getData() << " ";
}

