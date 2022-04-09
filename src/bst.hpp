#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <string>
#include "avltree.hpp"
#include "scapegoattree.hpp"

template <class T>
class BinaryTree{
	private:
		int type = 0; // 0 SGT, 1 AVL
		bool isSGT = true;
		bool isAVL = false;
		ScapeGoatTree sgt;
		BST avl;
	public:
		// empty
		BinaryTree();
		
		// copy
		BinaryTree(BinaryTree<T> &tree);
		
		// toggle BST type
		void setType(int _type);
		
		// get BST type
		int getType() { return type; }
		
		// add value
		void put(const T &val);
		
		// return height
		int getHeight();
		
		// return true iff element exists
		bool contains(T &val);
		
		// remove; return success
		bool remove(const T &val);
		
		// return the str
		std::string inorderString();
				
		// return the str
		std::string preorderString();
		
		// return the str
		std::string postorderString();
		
		// free memory
		~BinaryTree();
};

#include "bst.cpp"

#endif
