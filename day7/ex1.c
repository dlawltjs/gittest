#include <stdio.h>

void test2()
{
	puts("It is test2");
}

void test1()
{
	puts("It is test1");
	test2();

}

int main()
{
	int a;
	a++;
	++a;
	a += 2;
	a -= 3;
	printf("a값 : %d \r\n",a);
	
	test1();
	test2();

	return 0;
}
