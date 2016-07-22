#include <stdio.h>
#include <stdlib.h>

void lineColor(int li_color)
{
	 printf("%c[%dm",0x1b,li_color);
}
void setColor(int fore_color,int backg_color)
{
	 printf("%c[%d;%dm",0x1b,fore_color,backg_color);
}

void gotoxy(int x,int y)
{
	printf("%c[%d;%df",0x1b,y,x);
}

int main()
{
	 int fore_color;
	 system("clear");
	lineColor(33);	
	printf("====================");

	gotoxy(8,8);
	setColor(33,41);
	printf("hello");

	gotoxy(8,9);
	setColor(32,44);
    printf("world");
	setColor(0,0);




	for(int m=0;m<16;m++){
		gotoxy(0,m);
		lineColor(33);
		printf("|");
	}


	for(int n=0;n<16;n++){
		gotoxy(20,n);
		lineColor(33);
		printf("|");
	}

	 gotoxy(1,16);
	 printf("====================");

	 return 0;
}
