#pragma once
#include <iostream>

class Stack {
public:
	Stack();
	Stack(const Stack& s);
	Stack& operator= (const Stack& s);
	Stack(Stack&& s);
	Stack& operator= (Stack&& s);
	bool push(int a);
	int pop();
	int top() const { return _values[_top - 1]; }
	int size() const { return _top - 1; }
	void print() const;
	operator bool() const { return _top > 0 ? false : true; }
	~Stack() { delete[] _values; }
protected:
	int* _values = nullptr;
	int _size = 0;
	int _top = 0;
	bool resize();
};

