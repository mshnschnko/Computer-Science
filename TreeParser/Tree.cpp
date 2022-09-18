#include "Tree.h"
#include <algorithm>
//Tree::Tree(Tree const& tree) {}

//void Tree::copySons(Node* node) {
//	if (node) {
//		if (!node->sons.empty()) {
//			for (Node* son : node->sons) {
//				copySons(son);
//			}
//		}
//		node->name;
//	}
//}
//
//Tree::Tree(Tree const& tree) {
//	root = new Node();
//	root->name = tree.root->name;
//
//}



void Tree::parse(std::string filename) {
	std::ifstream file(filename);
	std::string line;
	std::string text;
	if (file.is_open()) {
		while (std::getline(file, line)) {
			text += line;
			text += "\n";
		}
		file.close();
		std::cout << text;
		int rootOpener = text.find("<");
		int rootCloser = text.find(">");
		if (rootOpener < text.length() && rootCloser < text.length() && rootOpener < rootCloser) {
			root->name = text.substr(rootOpener + 1, rootCloser - rootOpener - 1);
			std::cout << root->name << std::endl;
			text.erase(0, rootCloser + 1);
		}
		Node* curr = root;
		while (text.length() > 0) {
			int opener = text.find("<");
			int closer = text.find(">");
			if (opener < 0 || closer < 0)
				break;
			std::string name;
			if (opener < text.length() && closer < text.length() && opener < closer) {
				name = text.substr(opener + 1, closer - opener - 1); //подстрокой достаем название
				std::cout << name << std::endl;
				text.erase(0, closer + 1);
			}
			if ("/" + curr->name != name) {
				Node* newNode = new Node(curr, name);
				curr->sons.push_back(newNode);
				curr = newNode;
			}
			else {
				if (curr->parent) {
					curr = curr->parent;
				}
			}
		}
	}
	else
		std::cout << "Unable to open file";
}

void Tree::printway(std::string name1, std::string name2) {
	Node* node1 = searchWay(root, name1);
	Node* node2 = searchWay(root, name2);
	std::vector<Node*> way1;
	Node* curr = node1;
	//std::string way1 = node1->name;
	while (curr) {
		way1.push_back(curr);
		curr = curr->parent;
	}
	std::vector<Node*> way2;
	curr = node2;
	//std::string way2 = node2->name;
	while (curr) {
		way2.push_back(curr);
		curr = curr->parent;
	}
	Node* last = nullptr;
	while (!way1.empty() && !way2.empty() && (way1.back() == way2.back())) {
		last = way1.back();
		way1.pop_back();
		way2.pop_back();
	}
	std::cout << std::endl << std::endl << std::endl << "ways" << std::endl;
	for (int i = 0; i < way1.size(); i++) {
		std::cout << way1[i]->name << "->";
	}
	if(last)
		std::cout << last->name << "->";
	for (int i = way2.size() - 1; i > 0; i--) {
		std::cout << way2[i]->name << "->";
	}
	std::cout << way2[0]->name;
}

Tree::Node* Tree::searchWay(Node* node, std::string name) {
	if (!node || node->name == name) {
		return node;
	}
	if (!node->sons.empty()) {
		Node* finalNode;
		for (Node* son : node->sons) {
			finalNode = searchWay(son, name);
			if (finalNode && finalNode->name == name) {
				return finalNode;
			}
		}
	}
	else {
		return nullptr;
	}
}

void Tree::freeTree(Node* node) {
	if (node) {
		if (!node->sons.empty()) {
			for (Node* tree : node->sons) {
				freeTree(tree);
			}
		}
		delete node;
	}
}

Tree::~Tree() {
	if (root) {
		freeTree(root);
	}
}