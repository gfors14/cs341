#ifndef TREENODE_H
#define TREENODE_H
#include "Node.h"
#include <string>


/**
 * @class TreeNode
 *
 * A class that simulates a Node in a Binary Search Tree.
 */
class TreeNode : public Node
{
	public:
		/**
	     * Constructor
	     *
	     * @param[in]	   data		int
	    */	
		TreeNode(int data);
		
		/**
		* Copy constructor
		*
		* We need this since we have dynamically allocated
		* memory on this Class.
		*
		* @param[in]     node        Source TreeNode
		*/
		TreeNode(const TreeNode & node);
		
		/// Destructor
		~TreeNode();
		
		/// Accessor Methods
		
		/**
	     * Returns the data stored in the tree node.
		 *
	     * @return          int
	    */ 
		int getData();
		
		/**
	     * Returns a pointer to the left child of the given node.
		 *
	     * @return          TreeNode *
	    */ 		
		TreeNode * getLeftChild() const;
		
		/**
	     * Returns a pointer to the right child of the given node.
		 *
	     * @return          TreeNode *
	    */ 
		TreeNode * getRightChild() const;
		
		/**
	     * Returns a pointer to the parent of the given node.
		 *
	     * @return          TreeNode *
	    */ 
		TreeNode * getParent() const;
		
		TreeNode * getUncle() const;
		
		TreeNode * getGrandpa() const;
		
		/**
	     * Sets the left child of the given node.
	     *
		 * @param[in]	   TreeNode*	leftChild
	    */ 
		void setLeftChild(TreeNode * leftChild);
		
		/**
	     * Sets the right child of the given node.
	     *
		 * @param[in]	   TreeNode*	rightChild
	    */
		void setRightChild(TreeNode * rightChild);
		
		/**
	     * Sets the parent of the given node.
	     *
		 * @param[in]	   TreeNode*	parent
	    */
		void setParent(TreeNode * parent);
		
		void setGrandpa(TreeNode * grandpa);
		
		void setUncle(TreeNode * uncle);
		
		void setColor(char color);
		
		char getColor();
		
		
		
	private:
		int data_; 				// Data (int) of the given node
		TreeNode * leftChild_;	// Left child node of the given node
		TreeNode * rightChild_;	// Right child node of the given node
		TreeNode * parent_;		// Parent node of the given node
		TreeNode * grandpa_;
		TreeNode * uncle_;
		char color_;
		
	protected:
		/// Protected Constructor
		TreeNode() {}
};

#endif