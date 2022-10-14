#include "ExtendedStack.h"

bool ExtendedStack::push(std::initializer_list<int> lst) {
	for (int el : lst) {
		if (!Stack::push(el)) {
			return false;
		}
	}
	return true;
}

bool ExtendedStack::push(std::vector<int> lst) {
	for (int el : lst) {
		if (!Stack::push(el)) {
			return false;
		}
	}
	return true;
}

std::vector<int> ExtendedStack::pop(int count) {
	std::vector<int> out_vec;
	for (int i = 0; i < count; i++) {
		if (_top > 0) {
			out_vec.insert(out_vec.begin(), Stack::pop());
		}
	}
	return out_vec;
}

std::vector<int> ExtendedStack::top(int count) {
	std::vector<int> out_vec;
	int iter = (count > _top - 1) ? _top : count;
	int num = _top - 1;
	for (int i = 0; i < iter; i++) {
		out_vec.insert(out_vec.begin(), _values[num]);
		num--;
	}
	return out_vec;
}