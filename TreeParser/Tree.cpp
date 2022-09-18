#include "Tree.h"
#include <regex>
//Tree::Tree(Tree const& tree) {}



Tree::Tree(Tree const& tree) {
	root = new Node();
	root->name = tree.root->name;

}

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