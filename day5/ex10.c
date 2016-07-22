#include <stdio.h>

int main()
{
	char word[50] = "hi~ world";

	//word[0] = 'h';
	//word[1] = 'i';
	//word[2] = 0x00;
		
	//for(int i=0;i<2;i++) {
	//	printf("%c",word[i]);
	//}

	printf("%s \r\n",word);
/*
	int i=0;
	while(word[i] != 0x00) {
		printf("%c",word[i]);
		i++;
	}
*/
	for(int j=0;j<50;j++) {
		printf("%d,",word[j]);
	}
	
	printf("\r\n");
	scanf("%s",(word+9));

	//*(word+2) = 0x00;

	printf("your input is : %s \r\n",word);


	return 0;
}
