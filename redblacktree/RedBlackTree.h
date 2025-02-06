#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "BinarySearchTree.h"

class RedBlackTree : public BinarySearchTree
{
	public:
	RedBlackTree();
	~RedBlackTree();
	
	void insert(int data);
	
	void rotateLeft(TreeNode *& root, TreeNode *& node);
	void rotateRight(TreeNode *& root, TreeNode *& node);
	void balanceColor(TreeNode *& root, TreeNode *& newNode);
	void printRedNodes(TreeNode * root);
	void printBlackNodes(TreeNode * root);
	private:
	
	
};

#endif