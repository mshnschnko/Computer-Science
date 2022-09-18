#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Tree {
public:
	Tree() : root(new Node()) {};
	Tree(Tree const& tree) = default;
	Tree(Tree&& tree) = default;
	void parse(std::string filename);
	void printWay(std::string name1, std::string name2);
	~Tree();
private:
	class Node {
	public:
		Node() : parent(nullptr) {}
		Node(Node* parent) {
			this->parent = parent;
		};
		Node(Node* parent, std::string name) {
			this->parent = parent;
			this->name = name;
		};

		std::string name;
		std::vector<Node*> sons;
		Node* parent;
	};
	Node* searchWay(Node* node, std::string name);
	void copySons(Node* node);
	void freeTree(Node* node);
	Node* root;
};