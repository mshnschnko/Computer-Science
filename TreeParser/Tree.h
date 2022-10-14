#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Tree {
public:
	Tree() : root(new Node()) {};
	Tree(Tree const& tree);
	Tree(Tree&& tree);
	Tree& operator= (Tree&& tree) noexcept;
	void parse(std::string filename);
	void printWay(std::string name1, std::string name2);
	void printTree();
	~Tree();
private:
	class Node {
	public:
		Node() : parent(nullptr), level(0) {}
		Node(Node* parent) : level(0) {
			this->parent = parent;
		};
		Node(Node* parent, std::string name) : level(0) {
			this->parent = parent;
			this->name = name;
		};
		Node(Node* parent, std::string name, int level) {
			this->parent = parent;
			this->name = name;
			this->level = level;
		};

		std::string name;
		std::vector<Node*> sons;
		Node* parent;
		int level;
	};
	Node* searchWay(Node* node, std::string name);
	Node* copyTree(Node* nodeForCopy);
	void printNode(Node* node);
	void freeTree(Node* node);
	Node* root;
};