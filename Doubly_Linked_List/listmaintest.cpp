



#include "BootleggedLinkedList.h"
#include <iostream>

int main()
{
	BootleggedLinkedList<int> BLLL;

	// blank list
	std::cout << BLLL << "\n";

	BLLL.push_back(10);

	BLLL.push_back(20);
	BLLL.push_back(30);
	BLLL.push_back(50);

	// list has 10 20 30 50
	std::cout << BLLL << "\n";

	BLLL.pust_at(3, 40);

	// list has 10 20 30 40 50
	std::cout << BLLL << "\n";

	BLLL.erase_at(3);

	// list has 10 20 30 50
	std::cout << BLLL << "\n";

	// 10
	std::cout << BLLL.front() << "\n";

	// 50
	std::cout << BLLL.back() << "\n";

	BLLL.pop_front();

	// list has 20 30 50
	std::cout << BLLL << "\n";

	BLLL.pop_back();

	// list has 20 30 
	std::cout << BLLL << "\n";

	BLLL.clear();

	// list now only has dummy node
	std::cout << BLLL << "\n";

	system("PAUSE");

	return 0;
}






