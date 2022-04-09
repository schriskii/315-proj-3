#include <stdio.h>
#include <iostream>
#include "bst.hpp"

#include <stdlib.h>
#include <cstring>
#include <time.h>

clock_t test_insert(BinaryTree<int> *btree, int n){
	clock_t start = clock();
	btree->put(-1);
	return start;
}

clock_t test_remove(BinaryTree<int> *btree, int n){
	btree->put(-1);
	clock_t start = clock();
	btree->remove(-1);
	return start;
}

clock_t test_inorder(BinaryTree<int> *btree, int n){
	clock_t start = clock();
	btree->inorderString();
	return start;
}

clock_t test_height(BinaryTree<int> *btree, int n){
	clock_t start = clock();
	btree->getHeight();
	return start;
}

clock_t test_contains(BinaryTree<int> *btree, int n){
	int h = -1;
	clock_t start = clock();
	btree->contains(h);
	return start;
}

void test(int palette, int loops, clock_t func(BinaryTree<int> *, int), int type);

int main(int argc, char *argv[]) {
	
	int setting, amt;
	bool no_cout = true;
	
	if (!no_cout){
		std::cout << "SETTINGS:\n- 0: All SGT\n- 1: All AVL\n- 2: Insert\n- 3: Inorder\n- 4: Remove\n- 5: Height\n- 6: Contains\n\nChoice: ";
	}
	
	std::cin >> setting;
	
	if (!no_cout){
		std::cout << "\nEnter length of test, divided by 1,000 (recommended: 10-15): ";
	}
	
	std::cin >> amt;
	
	switch(setting){
		case 0:
			test(0, amt, test_insert, 0);
			test(1, amt, test_inorder, 0);
			test(2, amt, test_remove, 0);
			test(3, amt, test_height, 0);
			test(4, amt, test_contains, 0);
			break;
		case 1:
			test(0, amt, test_insert, 1);
			test(1, amt, test_inorder, 1);
			test(2, amt, test_remove, 1);
			test(3, amt, test_height, 1);
			test(4, amt, test_contains, 1);
			break;
		case 2:
			test(0, amt, test_insert, 0);
			test(1, amt, test_insert, 1);
			break;
		case 3:
			test(0, amt, test_inorder, 0);
			test(1, amt, test_inorder, 1);
			break;
		case 4:
			test(0, amt, test_remove, 0);
			test(1, amt, test_remove, 1);
			break;
		case 5:
			test(0, amt, test_height, 0);
			test(1, amt, test_height, 1);
			break;
		case 6:
			test(0, amt, test_contains, 0);
			test(1, amt, test_contains, 1);
			break;
	}
	
	if (!no_cout){
		std::cout << "\n\t\t\t\t\tcool\n\n";
	}
	
	/*
	
	BinaryTree<int> test;
	
	test.setType(0);
	
	test.put(5);
	test.put(10);
	test.put(51947);
	test.put(-1);
	test.put(-2);
	test.put(-100);
	test.put(60);
	test.put(80);
	test.put(1000);
	
	std::cout << test.inorderString() << "\n";
	
	test.remove(1000);
	
	std::cout << test.inorderString() << "\n";
	std::cout << test.preorderString() << "\n";
	std::cout << test.postorderString() << "\n";
	
	std::cout << "HEIGHT: " << test.getHeight() << "\n";
	
	int h = 80;
	std::cout << "HAS 80: " << test.contains(h) << "\n";
	h = 81;
	std::cout << "HAS 81: " << test.contains(h) << "\n";
	
	test.setType(1);
	
	test.put(5);
	
	BinaryTree<int> test2(test);
	
	test2.setType(0);
	
	std::cout << test2.inorderString() << "\n";
	
	*/
	
	return 0;
}

using namespace std;

void test(int palette, int loops, clock_t func(BinaryTree<int> *, int), int type){

	clock_t start, diff;
	double amount_time;
		
	auto btree = new BinaryTree<int>;
	
	btree->setType(type);
	
	for (int i = 0; i < 1000 * loops; i += 10){
		
		for (int j = 0; j < 10; j++){
			btree->put(i + j);
		}
		
		start = func(btree, i);
		
		diff = clock() - start;
		
		amount_time = diff * 1.0 / CLOCKS_PER_SEC;
		
		std::cout << i << " " << amount_time << " " << palette << "\n";
		
		std::cout << std::flush;
	}
	
	delete btree;
}
