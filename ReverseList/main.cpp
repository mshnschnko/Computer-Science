#include "List.h"

int main() {
	List* lst = new List();
	//lst->append(1);
	//lst->append(2);
	//lst->append(3);
	//lst->append(4);
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = nullptr;
	lst->head = n1;
	lst->print();
	lst->reverse();
	lst->print();
	return 0;
}