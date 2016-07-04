#include<stdio.h>

int main()
{
	char cmd;
	int bLoop;
	char buffer[64];
	char *pbuffer = buffer;
	int nTailIndex = 0;
	int num;

	for(int i=0;i<64;i++){
		*(pbuffer+i)=0;
	}

	bLoop=1;

	while(bLoop){
		scanf("%c",&cmd);
		getchar();

		switch(cmd){
			case 'a':	//add
				printf("what :");
				scanf("%c",&cmd);
				getchar();
				pbuffer[nTailIndex] = cmd;
				nTailIndex++;
				break;

			case 'd':	//delete
				nTailIndex--;
				pbuffer[nTailIndex] = 0x00;	
				break;

			case 'f':	//앞에서부터지우기
				for(int i=0;i<nTailIndex-1;i++){
					*(pbuffer+i) = *(pbuffer+i+1);
					num = i;
				}
				nTailIndex--;
				*(pbuffer+num+1) = 0x00;
				break;

			case 's':
				printf("%s\r\n",pbuffer);
				break;
			
			case 'q':
				printf("quit\r\n");
				bLoop=0;
				break;
		}
	}

	return 0;


	return 0;
}
