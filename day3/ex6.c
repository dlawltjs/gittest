#include <stdio.h>
#include <stdlib.h>
#include "../engine2d.h"


int main()
{
	int bLoop = 1;
	char cmd;
	int xpos, ypos;
	xpos = 1;
	ypos = 1;

	int orc_xpos,orc_ypos;
	orc_xpos = 10;
	orc_ypos = 10;

	while(bLoop) {
		scanf("%c",&cmd);
		switch(cmd) {
			case 'e':
			ypos -= 1;
			break;

			case 'd':
			ypos += 1;
			break;
			
			case 'f':
			xpos += 1;
			break;
			
			case 's':
			xpos -= 1;
			break;
			
			case 'q':
			bLoop = 0;
			break;

		}
		system("clear");
		//주인공출력
		drawMyBox(xpos,ypos,44,1);
		//몸AI
		if(orc_xpos > xpos) {
			orc_xpos -= 1;
		}
		else if(orc_xpos < xpos) {
			orc_xpos +=1;
		}
		else {
		}
		//몸출력
		drawMyBox(orc_xpos,orc_ypos,42,3);

		
		gotoxy(0,20);
		printf("---------------------------");
		printf("%d,%d \r",xpos,ypos);

	}

	//drawMyBox(2,2,41);

	return 0;
}
