#include "List.h"

List::~List() {
	if (!head)
		return;
	Node* curr = head;
	if (head->next) {
		Node* next = curr->next;
		while (next) {
			next = curr->next;
			delete curr;
		}
	}
	delete curr;
		
}

void List::reverse() {
	Node* curr, * next, * prev = nullptr;
	curr = head;
	while (curr != nullptr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

void List::append(int x) {
	Node* curr = nullptr;
	if (!head) {
		curr = new Node(x);
	}
	while (curr->next) { curr = curr->next; }
	Node* forAdd = new Node(x);
	curr = forAdd;
}

void List::pop() {
	Node* curr = head;
	while (curr->next) { curr = curr->next; }
	delete curr;
}

void List::del(int idx) {
	Node* curr = head;
	Node* prev = curr;
	for (int i = 0; i < idx - 1; i++) {
		prev = prev->next;
	}
	
	curr->next = curr->next->next;
	
}

void List::print() {
	Node* curr = head;
	while (curr) {
		std::cout << curr->value << " ";
		curr = curr->next;
	}
	std::cout << std::endl;
}