#include <stdio.h>

int main()
{
	FILE *pFile;
	pFile = fopen("test.txt","w");

	fprintf(pFile,"%d,%s \r\n",100,"hello");

	fclose(pFile);

	pFile = fopen("test.txt","r");
	char szstr[128];
	int num;
	fscanf(pFile,"%d,%s \r\n",&num,szstr);

	return 0;
}
