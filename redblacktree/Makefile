driver.o: driver.cpp Node.o TreeNode.o BinarySearchTree.o RedBlackTree.o
	g++ driver.cpp Node.o TreeNode.o BinarySearchTree.o RedBlackTree.o -o blah
	
Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o
	
TreeNode.o: TreeNode.cpp
	g++ -c TreeNode.cpp -o TreeNode.o
	
BinarySearchTree.o: BinarySearchTree.cpp
	g++ -c BinarySearchTree.cpp -o BinarySearchTree.o
	
RedBlackTree.o: RedBlackTree.cpp
	g++ -c RedBlackTree.cpp -o RedBlackTree.o
	
clean:
	rm -f Node.o TreeNode.o BinarySearchTree.o RedBlackTree.o