#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define BUFFER_SIZE 64

void waitForUserInput()
{
	system("pause");
}

void verySafeReadFile(char* buffer, const char* fileName)
{
	int c;
	FILE* file = fopen(fileName, "rb");
	if (!file)
	{
		fprintf(stderr, "Error opening file '%s'\n", fileName);
		waitForUserInput();		
		exit(1);
		return;
	}
	while (!feof(file))
	{
		*buffer++ = fgetc(file);
	}
	*buffer = '\0';
	fclose(file);
}

int main()
{
	int ret = 0;
	int i;
	const char* fileName = "safeFile.txt";
	char name[BUFFER_SIZE];
	memset(name, 0xFF, BUFFER_SIZE);
	printf("Some address, why not: %p\n", &name);
	verySafeReadFile(name, fileName);
	printf("Content of file '%s', %s, it has %i chars!\n", fileName, name, strlen(name));

	system("pause");
	return ret;
}
