#include "TreeNode.h"
#include <iostream>

TreeNode::TreeNode(int data)
{
	// We could also use the initialization list here...
	data_ = data;
	leftChild_ = nullptr;
	rightChild_ = nullptr;
	parent_ = nullptr;
	grandpa_ = nullptr;
	uncle_ = nullptr;
}

TreeNode::TreeNode(const TreeNode & node)
{
	data_ = node.data_;
	leftChild_ = node.getLeftChild();
	rightChild_ = node.getRightChild();
	parent_ = node.getParent();
//	grandpa_ = node.getParent()->getParent();
}

TreeNode::~TreeNode()
{
	// Recursive Delete
	if (leftChild_ != nullptr)
	{
		delete leftChild_;
	}
	
	if (rightChild_ != nullptr)
	{
		delete rightChild_;
	}
}

int TreeNode::getData()
{
	return data_;
}

TreeNode * TreeNode::getLeftChild() const
{
	return leftChild_;
}

TreeNode * TreeNode::getRightChild() const
{
	return rightChild_;
}

TreeNode * TreeNode::getParent() const
{
	return parent_;
}

TreeNode * TreeNode::getUncle() const
{
	return uncle_;
}

TreeNode * TreeNode::getGrandpa() const
{
	return grandpa_;
}

void TreeNode::setLeftChild(TreeNode * child)
{
	leftChild_ = child;
}

void TreeNode::setRightChild(TreeNode * child)
{
	rightChild_ = child;
}

void TreeNode::setParent(TreeNode * parent)
{
	parent_ = parent;
}

void TreeNode::setGrandpa(TreeNode * grandpa)
{
	grandpa_ = grandpa;
}

void TreeNode::setUncle(TreeNode * uncle)
{
	uncle_ = uncle;
}

void TreeNode::setColor(char color)
{
	if(color == 'R')
	{
		color_ = 'R';
	}
	else
	{
		color_ = 'B';
	}
}

char TreeNode::getColor()
{
	//std::cout << color_ << std::endl;
	return color_;
}

