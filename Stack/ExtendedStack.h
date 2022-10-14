#pragma once
#include <vector>
#include "Stack.h"

class ExtendedStack : public Stack {
public:
	bool push(std::initializer_list<int> lst);
	bool push(std::vector<int> lst);
	std::vector<int> pop(int count);
	std::vector<int> top(int count);
};