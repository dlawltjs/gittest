#include <stdio.h>

int main()
{
	char m = 0xaf; //1010 1111
	char m1 = m & 0x0f; //0000 1111
	char m2 = m | 0x10; //0001 0000
	char m3 = m ^ 0x5f; //0101 1111
	char m4 = ~m;	

	printf("%x %x %x %x \r\n",m1,m2,m3,m4);

	return 0;
}
