#include <stdio.h>
#include <string.h>

int main()
{
	char *pstrcmd = "move position 123,56";

	char *ptr = strstr(pstrcmd,"position"); //특정문자찾기. 찾으면 포인터 반환

	printf("%s \r\n",ptr);

	char pstrTemp[128];

	strncpy(pstrTemp,pstrcmd,4); //copy할 갯수지정

	printf("%s \r\n",pstrTemp);

	char *pstrclone;

	pstrclone = strdup(pstrcmd); //할당

	pstrclone[0] = 'a';

	//pstrclone = pstrcmd;

	//pstrcmd[0] = 'n';

	printf("%s \r\n",pstrclone);
	printf("%s \r\n",pstrcmd);	

	return 0;
}
