#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	//char ptr[] = "move position 30,20";
	char *ptr = strdup("move position 30,20");
	char *ptrTmep;

	ptrTmep = strtok(ptr," "); //공백문자가 생기면 잘라내기.
	
	printf("%s \r\n",ptrTmep);
	printf("%s \r\n",strtok(NULL," "));
	//printf("%s \r\n",strtok(NULL," "));

	ptrTmep = strtok(NULL,",");
	printf("%d \r\n",atoi(ptrTmep)+1); //숫자로 잘라내기

	ptrTmep = strtok(NULL,",");
	printf("%d \r\n",atoi(ptrTmep)+1);

	return 0;
}
