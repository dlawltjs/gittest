#include <stdio.h>

int main()
{
	printf("hello \r\n");

	printf("\x1b[31m");
	printf("hello \r\n");
	
	printf("\x1b[1;31m");
	printf("hello vt100 \r\n");

	printf("\x1b[4;35m");
	printf("hello \r\n");

	printf("\x1b[33m");
	printf("hello \r\n");

	printf("\x1b[5;32m");
	printf("hello \r\n");

	printf("\x1b[36m");
	printf("hello \r\n");

	printf("\x1b[7;34m");
	printf("hello \r\n");

	printf("\x1b[30m");
	printf("hello \r\n");


	return 0;
}
