#ifdef BINARY_TREE_H
#include <math.h>

// empty
template <class T>
BinaryTree<T>::BinaryTree(){
	// nothing
}

// copy
template <class T>
BinaryTree<T>::BinaryTree(BinaryTree<T> &tree){
	
	int original_type = tree.getType();
	
	setType(0);
	tree.setType(0);
	
	for (int h = 0; h < 2; h++){
	
		std::string str = tree.inorderString();

		// https://www.geeksforgeeks.org/convert-a-string-to-integer-array-in-c-c/; adapted to handle negatives

		// get length of string str
		int str_length = str.length();

		// create an array with size as string
		// length and initialize with 0
		int arr[str_length] = { 0 };

		int j = 0, i, sum = 0;
		
		bool negative = false;

		// Traverse the string
		for (i = 0; str[i] != '\0'; i++) {
			if (str[i] == '-'){
				negative = true;
				continue;
			}
			if (str[i] == ' '){
				if (negative){
					arr[j] *= -1;
				}
				negative = false;
				j++;
			}
			else {

				// subtract str[i] by 48 to convert it to int
				// Generate number by multiplying 10 and adding
				// (int)(str[i])
				arr[j] = arr[j] * 10 + (str[i] - 48);
			}
		}

		for (int i = 0; i < j; i++){
			put(arr[i]);
		}
		
		setType(1);
		tree.setType(1);
	}
	
	setType(original_type);
	tree.setType(original_type);
}
		
// toggle BST type
template <class T>
void BinaryTree<T>::setType(int _type){
	type = _type;
	isSGT = false;
	isAVL = false;
	switch(type){
		case 0:
			isSGT = true;
			break;
		case 1:
			isAVL = true;
			break;
	}
}

// add value
template <class T>
void BinaryTree<T>::put(const T &val){
	if (isSGT){
		sgt.add(val);	
	}
	if (isAVL){
		avl.insert(val);
	}
}

// return height
template <class T>
int BinaryTree<T>::getHeight(){
	if (isSGT){
		return log2(sgt.size());
	}
	if (isAVL){
		return log2(avl.size);
	}
	return 0;
}

// return true iff element exists
template <class T>
bool BinaryTree<T>::contains(T &val){
	if (isSGT){
		return sgt.search(val);
	}
	if (isAVL){
		return avl.find(val);
	}
	return false;
}

// TODO return success
template <class T>
bool BinaryTree<T>::remove(const T &val){
	if (isSGT){
	
		// SUPER JANKY hack, since I realised late into the project that my SGT doesn't have a remove func... ugh
		
		std::string str = sgt.inorder();

		// https://www.geeksforgeeks.org/convert-a-string-to-integer-array-in-c-c/; adapted to handle negatives

		// get length of string str
		int str_length = str.length();

		// create an array with size as string
		// length and initialize with 0
		int arr[str_length] = { 0 };

		int j = 0, i, sum = 0;
		
		bool negative = false;

		// Traverse the string
		for (i = 0; str[i] != '\0'; i++) {
			if (str[i] == '-'){
				negative = true;
				continue;
			}
			if (str[i] == ' '){
				if (negative){
					arr[j] *= -1;
				}
				negative = false;
				j++;
			}
			else {

				// subtract str[i] by 48 to convert it to int
				// Generate number by multiplying 10 and adding
				// (int)(str[i])
				arr[j] = arr[j] * 10 + (str[i] - 48);
			}
		}
		
		sgt.makeEmpty();
		
		bool found = false;

		for (int i = 0; i < j; i++){
			if (arr[i] == val){
				found = true;
			}
			else{
				sgt.add(arr[i]);
			}
		}
	}
	if (isAVL){
		return avl.remove(val);
	}
	return false;
}

// return the str
template <class T>
std::string BinaryTree<T>::inorderString(){
	if (isSGT){
		return sgt.inorder();
	}
	if (isAVL){
		return avl.inorder();
	}
	return "";
}
		
// return the str
template <class T>
std::string BinaryTree<T>::preorderString(){
	if (isSGT){
		return sgt.preorder();
	}
	if (isAVL){
		return avl.preorder();
	}
	return "";
}

// return the str
template <class T>
std::string BinaryTree<T>::postorderString(){
	if (isSGT){
		return sgt.postorder();
	}
	if (isAVL){
		return avl.postorder();
	}
	return "";
}

// free memory
template <class T>
BinaryTree<T>::~BinaryTree(){
	// nothing
}

#endif
