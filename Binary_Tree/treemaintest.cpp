



#include <iostream>

#include "BootleggedBinaryTree.h"

int main()
{

	BootleggedBinaryTree<int> BLBT;

	BLBT.insert(3);
	BLBT.insert(1);
	BLBT.insert(5);

	// 1 3 5
	BLBT.in_order_traversal();
	std::cout << "\n";

	BLBT.insert(4);

	// 1 3 4 5
	BLBT.in_order_traversal();
	std::cout << "\n";

	BLBT.insert(4);

	// 1 3 4 4 5
	BLBT.in_order_traversal();
	std::cout << "\n";

	// it exists in the tree
	BLBT.find(4);

	// it doesn't exist in the tree
	BLBT.find(7);

	BLBT.erase(4);

	// 1 3 4  5
	BLBT.in_order_traversal();
	std::cout << "\n";

	BLBT.erase(3);

	// 1 4 5
	BLBT.in_order_traversal();
	std::cout << "\n";


	system("pause");


}



