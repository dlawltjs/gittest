#include <stdio.h>

//#define pi 3.14

const double pi = 3.14;


int main()
{
	//pi = 3.14; //에러

	double pi = 1.14;
	
	int a= 10,b=20;

	const int *ap; //포인터 사용시 주소값 변경가능
	
	ap = &a;
	ap = &b;

	b = 21; //변경가능

	//*ap = 21; //에러

	//pi = 2.14;
	//_pi = 2.14;

	printf("%f %d \r\n",pi,*ap);

}
