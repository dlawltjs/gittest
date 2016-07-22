#include <stdio.h>
#include <string.h>

int main()
{
	char strcmd[128];
	//scanf("%s",strcmd);
	gets(strcmd); //scanf는 공백을 읽지 못하기 때문에 사용

	puts(strcmd);
	//printf("%s \r\n",strcmd);

	char ch = getchar(); //문자 하나 입력받음
	putchar(ch);
	
	
	return 0;
}
