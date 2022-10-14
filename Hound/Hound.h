#pragma once
#include<iostream>
#include<functional>
#include<stack>
#include<string>

class Hound{
public:
	Hound() = default;
	Hound(std::string string) : _string(string) {};
	void addTransformation(std::function<std::string(std::string)> operation);
	void popTransformation();
	void clearTranformationStack();
	std::string run();
	~Hound() { clearTranformationStack(); }
	std::string getString() { return _string; }
private:
	std::stack<std::function<std::string(std::string)>> _stack;
	std::string _string;
};

