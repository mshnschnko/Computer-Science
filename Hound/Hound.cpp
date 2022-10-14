#include "Hound.h"

void Hound::addTransformation(std::function<std::string(std::string)> operation) {
	_stack.push(operation);
}

void Hound::popTransformation() {
	_stack.pop();
}

void Hound::clearTranformationStack() {
	while (!_stack.empty())
		_stack.pop();
}

std::string Hound::run() {
	while (!_stack.empty()) {
		_string = _stack.top()(_string);
		_stack.pop();
	}
	return _string;
}