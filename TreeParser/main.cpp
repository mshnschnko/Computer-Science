#include "Tree.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

void MemoryLeaks(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
}

int main() {
	Tree t;
	t.parse("testdoc.txt");
	t.printTree();
	t.printWay("FirstSon", "Fourth");
	Tree t2(std::move(t));
	t.printTree();
	t2.printTree();
	std::cout << std::string(10, '=') << std::endl;
	Tree t3;
	std::cout << std::string(10, '=') << "t3" << std::endl;
	t3 = std::move(t2);
	t3.printTree();
	//Tree t4(t3);
	//std::cout << std::string(10, '=') << "t4" << std::endl;
	//t4.printTree();
	MemoryLeaks();
	return 0;
}