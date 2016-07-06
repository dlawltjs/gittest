#include <stdio.h>
#include <stdlib.h>

int main()
{	
	int a;
	int *ip;

	//ip = &a; //써주지 않으면 할당받은 공간 없기때문에 에러
	
	ip = (int *)malloc(4); //메모리할당
	
	*ip = 10;

	printf("%d \r\n",*ip);

	free(ip);//기억공간 반환
	
	return 0;

}
