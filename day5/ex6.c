#include <stdio.h>

int main()
{
	int num[] = {3,7,15,6,8,2};

	printf("배열의 갯수 : %d \r\n",sizeof(num)/sizeof(int));

	int sum = 0;
	int max = 0;
	int min;

	for(int i=0;i< sizeof(num)/sizeof(int);i++) {
		sum += num[i];
		min = num[i]; 
		
		if(max < num[i]) {
			max = num[i];

		}
		if(min > num[i]) {
			min = num[i];
		
		}
	}

	printf("배열의 합 : %d \r\n",sum);
	printf("최대값 : %d \r\n",max); 
	printf("최솟값 : %d \r\n",min);
	
	return 0;
}
