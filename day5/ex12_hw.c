#include <stdio.h>

int main()
{
	char cmd;
	int bLoop;
	char buffer[64];
	char *pbuffer = buffer;
	int nTailIndex = 0;

	for(int i=0;i<64;i++) {
		buffer[i] = 0;
	}

	bLoop = 1;
	while(bLoop) {

		scanf("%c",&cmd);
		getchar();

		switch(cmd) {
			case 'a': //add
			printf("what : ");
			scanf("%c",&cmd);
			getchar();
			*pbuffer = cmd;
			pbuffer++;
			break;

			case 'd':
			pbuffer--;
			*pbuffer = 0x00;
			break;

			case 'f': //앞에서부터 지우기
			for(int i=0;i<sizeof(buffer);i++) {
				*pbuffer = *(pbuffer+4);
			}
			pbuffer--;
			*pbuffer = 0x00;	

			break;

			case 's':
			printf("%s \r\n",buffer);
			break;
			
			case 'q':
			printf("quit \r\n");
			bLoop = 0;
			break;
			 

		}

	}

}
