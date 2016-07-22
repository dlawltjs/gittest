#include <stdio.h>

void exchange(int *pa, int *pb)
{
	int c;

	c = *pa;
	*pa = *pb;
	*pb = c;
}

int main()
{
	int a = 7;
	int b = 5;

	exchange(&a, &b);

	printf("%d %d \r\n",a,b);

	return 0;
}
