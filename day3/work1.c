#include <stdio.h>
#include <stdlib.h>
#include "../engine2d.h"
int drawMyCar(int nXpos,int nYpos,int nColor)
{
	int ix, iy;
	
	setColor(30,nColor);
	ix = 0;
	
	//자동차상단
	for(iy = 0;iy <= 2;iy++) {
		for(ix = 0;ix <= 8;ix++) {
		gotoxy(ix+nXpos+3,iy+nYpos);
		printf(" ");
		}
			
	}
	
	//자동차하단
	for(iy = 0;iy <= 1;iy++) {
		for(ix = 0;ix <= 14;ix++) {
		gotoxy(ix+nXpos,iy+nYpos+2);
		printf(" ");
		}
			
	}
	
	//왼쪽바퀴
	setColor(30,47);
	for(iy = 0;iy <= 1;iy++) {
		for(ix = 0;ix <= 2;ix++) {
		gotoxy(ix+nXpos+3,iy+nYpos+3);
		printf(" ");
		}
			
	}

	//오른쪽바퀴
	for(iy = 0;iy <= 1;iy++) {
		for(ix = 0;ix <= 2;ix++) {
		gotoxy(ix+nXpos+9,iy+nYpos+3);
		printf(" ");
		}
			
	}

	setColor(0,0);
}

int main()
{
	int bLoop = 1;
	char cmd;
	int xpos, ypos;
	xpos = 1;
	ypos = 1;

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
		drawMyCar(xpos,ypos,44);
		gotoxy(0,20);
		printf("---------------------------");
		printf("%d,%d \r",xpos,ypos);

	}

	//drawMyBox(2,2,41);

	return 0;
}
