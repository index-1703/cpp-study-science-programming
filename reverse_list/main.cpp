#include <iostream>
#include "ReverseList.h"

int main(void) {
	ReverseList<int> rl;
	
	rl.push_back(1);
	rl.push_back(2);
	rl.push_back(3);
	rl.push_back(4);
	rl.push_back(5);

	rl.print();
	rl.reverse();
	rl.print();
	rl.reverse();
	rl.print();

	return 0;
}