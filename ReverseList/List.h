#pragma once
#include <stdio.h>
#include <iostream>

class Node {
public:
	Node() : value(0), next(nullptr) {};
	Node(int x) : value(x), next(nullptr) {};
	int value;
	Node* next;
	Node operator= (const Node& node) {
		this->value = node.value;
		this->next = node.next;
		return *this;
	}
	~Node() { delete next; }
};

class List {
public:
	List() : head(nullptr) {};
	void reverse();
	void append(int x);
	void pop();
	void del(int idx);
	void print();
	Node* head;
	~List();
};

