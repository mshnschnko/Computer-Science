#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Tree {
public:
	Tree() : root(new Node()) {};
	Tree(Tree const& tree);
	Tree(Tree&& tree) = default;
	void parse(std::string filename);
	void printway(std::string name1, std::string name2);
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
	void 
	void freeTree(Node* node);
	Node* root;
};