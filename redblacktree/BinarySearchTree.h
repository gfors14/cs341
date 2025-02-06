#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"
#include <iostream>

/**
 * @class BinarySearchTree
 *
 * A Class that simulates a Binary Search Tree.
 */
class BinarySearchTree
{
	public:
		/// Constructor
		BinarySearchTree();
		
		/**
		* Copy constructor
		*
		* We need this since we have dynamically allocated
		* memory on this Class.
		*
		* @param[in]     tree        Source BinarySearchTree
		*/
		BinarySearchTree(const BinarySearchTree & tree);
		
		/// Destructor
		virtual ~BinarySearchTree();
		
		/**
	     * Returns a pointer to the root node of the BST.
		 *
	     * @return          TreeNode*
	    */ 
		TreeNode * getRoot() const;
		
		/**
	     * Inserts a data element into the BST.
	     *
		 * @param[in]	   int	data
	    */ 
		virtual void insert(int data) = 0;
		
		void setRoot(TreeNode * root);
		/**
   	  	* Helper method to insert a TreeNode into the BST.
    	*
	 	* @param[in]	   TreeNode*	root	
	 	* @param[in]	   TreeNode*	newNode
	 	*
     	* @return          TreeNode*
    	*/ 
		TreeNode * insertNode(TreeNode * root, TreeNode * newNode);
		
		void inorder(TreeNode * root);
		
		void preorder(TreeNode * root);
		
		void postorder(TreeNode * root);
		
	private:
		TreeNode * root_; // Pointer to the root node of the BST
};

#endif