#include <iostream>
#include "Stack.h"

Stack::Stack() {
	_values = new int[1];
	_size = 1;
	_top = 0;
}

Stack::Stack(const Stack& s) {
	if (!s) {
		_values = new int[s._size];
		_size = s._size;
		_top = s._top;
		for (int i = 0; i < _size; i++) {
			_values[i] = s._values[i];
		}
	}
	else {
		_values = new int[1];
		_size = 1;
		_top = 0;
	}
}

Stack& Stack::operator= (const Stack& s) {
	if (!s) {
		delete[] _values;
		_size = s._size;
		_top = s._top;
		_values = new int[s._size];
		for (int i = 0; i < _size; i++) {
			_values[i] = s._values[i];
		}
	}
	else {
		_values = new int[1];
		_size = 1;
		_top = 0;
	}
	return *this;
}

Stack::Stack(Stack&& s) {
	_size = s._size;
	_top = s._top;
	_values = s._values;
	s._values = nullptr;
}

Stack& Stack::operator= (Stack&& s) {
	delete[] _values;
	_size = s._size;
	_top = s._top;
	_values = s._values;
	s._values = nullptr;
	return *this;
}

bool Stack::resize() {
	int* new_values = new int[_size + 1];
	if (!new_values)
		return false;
	for (int i = 0; i < _size; i++) {
		new_values[i] = _values[i];
	}
	delete _values;
	_values = new_values;
	_size++;
	return true;
}

bool Stack::push(int a) {
	if (_top < _size) {
		_values[_top++] = a;
	}
	else {
		if (resize()) {
			_values[_top++] = a;
		}
		else {
			return false;
		}
	}
	return true;
}

int Stack::pop() {
	if (_top > 0) {
		_top--;
		return _values[_top];
	}
	else
		return 0;
}

void Stack::print() const {
	for (int i = 0; i < _top; i++) {
		std::cout << _values[i] << " ";
	}
	std::cout << std::endl;
}