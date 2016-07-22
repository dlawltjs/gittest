#include <stdio.h>

int main()
{
	int ary[5] = {1,2,3,4,5};
	int ary2[5];
	int *pAry;

	pAry = ary; //처리되는 명령어

	printf("%d %d %d \r\n",*(pAry+1),*(ary+1),pAry[1]);
	
	//ary2 = ary; //처리 안되는 명령어

	return 0;
}
