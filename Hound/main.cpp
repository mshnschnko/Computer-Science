#include "Hound.h"
#include "StringOperations.h"

int main() {
	Hound s("STR ing123");
	std::string ss = "asd";
	std::function<std::string(std::string)> operation1 = &toUpperCase;
	std::function<std::string(std::string)> operation2 = &toLowerCase;
	std::function<std::string(std::string)> operation3 = &reverse;
	std::function<std::string(std::string)> operation4 = &removeSpaces;
	std::function<std::string(std::string)> operation5 = &removeDigits;
	s.addTransformation(operation1);
	s.addTransformation(operation2);
	s.addTransformation(operation3);
	s.addTransformation(operation4);
	s.addTransformation(operation5);
	std::cout << s.run() << std::endl;
	s.addTransformation(operation2);
	s.clearTranformationStack();
	std::cout << s.run() << std::endl;
	return 0;
}