#include <stdio.h>

int teatAr[5] = {100,101,102,103,104};
char teatAr2[5] = {100,101,102,103,104};


int main()
{
	printf("%d \r\n",teatAr[1]);

	int *pTemp = teatAr;

	printf("%d \r\n",pTemp[1]);
	printf("%d \r\n",pTemp[2]);
	printf("%d , %d , %d \r\n",pTemp,pTemp+1,pTemp+2);
	printf("%d , %d , %d \r\n",*pTemp,*(pTemp+1),*(pTemp+2));
	
	char *pTemp2 = teatAr2;
	printf("%d , %d , %d \r\n",pTemp2,pTemp2+1,pTemp2+2);
	return 0;
}
