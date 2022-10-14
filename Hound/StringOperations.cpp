#include"StringOperations.h"

std::string toUpperCase(std::string str) {
	for (auto& letter : str) {
		if (letter >= 'a' && letter <= 'z') {
			letter -= 32;
		}
	}
	return str;
}

std::string toLowerCase(std::string str) {
	for (auto& letter : str) {
		if (letter >= 'A' && letter <= 'Z') {
			letter += 32;
		}
	}
	return str;
}

std::string reverse(std::string str) {
	std::string newStr;
	for (int i = str.size() - 1; i >= 0; i--) {
		newStr += str.at(i);
	}
	return newStr;
}

std::string removeSpaces(std::string str) {
	std::string newStr;
	for (int i = 0; i < str.size(); i++) {
		if (str.at(i) != ' ')
			newStr += str.at(i);
	}
	return newStr;
}

std::string removeDigits(std::string str) {
	std::string newStr;
	for (char letter : str) {
		if (letter >= '0' && letter <= '9')
			continue;
		else
			newStr += letter;
	}
	return newStr;
}