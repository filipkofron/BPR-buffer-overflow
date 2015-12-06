#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int doStuff(const char *str, int a)
{
	WinExec(str, a);
	return 0;
}

int main()
{
	printf("Hello, world!!! This is amazing!\n");
	printf("WinExec: %p\n", WinExec);
	doStuff("calc", SW_SHOW);
	system("pause");
	return 0;
}