#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//add 10,20
	//sub 5,2
	//mul 4,3
	//div 8,2
	
	char strcmd[128];

	scanf("%s",strcmd);

	char *ptrTemp;
	char *pcmd;
	int a,b;

	ptrTemp = strtok(strcmd," ");

	pcmd = strdup(ptrTemp);
	
	a = atoi( strtok(NULL,",") );
	b = atoi( strtok(NULL,",") );
	
	if(strcmp(pcmd,"add") == 0) {
		printf("덧셈 : %d \r\n",a+b);

	}
	else if( strcmp(pcmd,"sub") == 0) {
		printf("뺄셈 : %d \r\n",a-b);
	}
	else if( strcmp(pcmd,"mul") == 0) {
		printf("곱셈 : %d \r\n",a*b);
	}
	else if( strcmp(pcmd,"div") == 0) {
		printf("나눗셈 : %d \r\n",a/b);
	}


	return 0;
}
