#include <stdio.h>

int main()
{
	char strTemp[64];
	char strTemp2[64];

	scanf("%s %s",strTemp,strTemp2);
	
	printf("%s, %s \r\n",strTemp,strTemp2);

	int nsize1, nsize2;
	int i;

	for(i=0;i<strTemp[i] != 0x00;i++);
	nsize1 = i;

	for(i=0;i<strTemp2[i] != 0x00;i++);
	nsize2 = i;
	
	printf("%d, %d \r\n",nsize1,nsize2);
	
	if(nsize1 != nsize2) {
		printf("not match \r\n");
	}
	
	else {
		int bMatch = 1;
		for(int i=0;i<nsize1;i++) {
			if(strTemp[i] != strTemp2[i]) {
				bMatch = 0;
				break;

			}
		}

		if(bMatch) {
			printf("match \r\n");
		}
		else {
			printf("not match \r\n");
		}
	}


/*
	int nCount = 0;

	for(int i=0;strTemp[i] != 0;i++) {
		if(strTemp[i] == 'l') {
			nCount++;

		}
	}

	printf("%d \r\n",nCount);
*/

	return 0;
}
