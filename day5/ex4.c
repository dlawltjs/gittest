#include <stdio.h>

//void assign(long a)
void assign(int *a)
{
	printf("a : %u \r\n",a);
	
	//int *c = (int *)a;

	//*((int *)4294953996) = 100;
	*a = 100;
}

int main()
{
	int b = 0;

	printf("%u \r\n",&b);

	//assign(4294953996);
	//assign((long)&b);
	assign(&b);

	printf("%d \r\n",b);

	return 0;

}
