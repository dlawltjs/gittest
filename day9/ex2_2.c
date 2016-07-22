#include <stdio.h>

int nCount = 0;
static int nCount2 = 0;
void foo()
{
	nCount++;
	puts("It is foo");
	printf("%d \r\n",nCount);
	nCount2++;
	printf("%d \r\n",nCount2);
}


