#include <iostream>
#include "Stack.h"
#include "ExtendedStack.h"

int main() {
	//Stack s;
	//s.push(1);
	//s.push(2);
	//s.print();
	//std::cout << s.top() << std::endl;
	//std::cout << s.pop() << std::endl;
	//s.print();
	//std::cout << "empty? " << (s) << std::endl;
	//s.pop();
	//std::cout << "empty? " << (s) << std::endl;
	//s.push(12);
	//s.push(39);
	//Stack s2(s);
	//s2.print();
	//Stack s3;
	//s3 = s2;
	//s3.print();
	//Stack s4(std::move(s3));
	//std::cout << "after move" << std::endl;
	//s4.print();
	std::vector<int> lst = { 1, 2, 3 };
	ExtendedStack s;
	s.push(lst);
	s.push({ 4, 5, 6 });
	s.print();

	std::vector<int> after_top = s.top(2);
	std::cout << "top 2: ";
	for (int el : after_top) {
		std::cout << el << " ";
	}
	std::cout << std::endl;

	std::vector<int> after_top7 = s.top(7);
	std::cout << "top 7: ";
	for (int el : after_top7) {
		std::cout << el << " ";
	}
	std::cout << std::endl;

	s.print();
	s.pop(3);

	s.print();
	std::vector<int> after_pop = s.pop(4);
	s.print();
	for (int el : after_pop) {
		std::cout << el << " ";
	}
	return 0;
 }