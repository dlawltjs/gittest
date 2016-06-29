#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("clear");

	printf("\x1b[3;3f");
	printf("hello");

	printf("\x1b[5;2f");
	printf("world");

	
	printf("\x1b[0;20f");
	printf("|");

	printf("\x1b[1;20f");
	printf("|");
	printf("\x1b[2;20f");
	printf("|");
	printf("\x1b[3;20f");
	printf("|");
	printf("\x1b[4;20f");
	printf("|");
	printf("\x1b[5;20f");
	printf("|");
	printf("\x1b[6;20f");
	printf("|");
	printf("\x1b[7;20f");
	printf("|");



	
	return 0;
}

