#include <stdio.h>
#include <string.h>

int main()
{
	char *pstr = "hello world";
	char strTemp[128];

	strcpy(strTemp,pstr);

	strTemp[0] = 'R';
	printf("원본 : %s \r\n",pstr);

	printf("%s울 복사했습니다.  \r\n",strTemp);

	printf("문자열의 길이 : %d \r\n",strlen(strTemp));

	int cmp = strcmp("hello world","aello");

	printf("%d \r\n",cmp);
	

	char *pstr2 = ",hi world";

	strcat(strTemp,pstr2);
	printf("%s \r\n",strTemp);
		
}
