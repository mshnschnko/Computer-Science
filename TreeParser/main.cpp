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
	t.printWay("FirstSon", "Fourth");
	MemoryLeaks();
	return 0;
}