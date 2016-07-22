#include <stdio.h>
#include <stdlib.h>

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
	fore_color = 31;
	system("clear");
	//printf("%c[%dm",0x1b,fore_color);
	
	printf("====================");
	gotoxy(8,8);
	setColor(33,41);
	printf("hello");

	gotoxy(8,9);
	setColor(32,44);
	printf("world");
	setColor(0,0);
	
	gotoxy(20,1);
	printf("|");
	gotoxy(20,2);
	printf("|");
	gotoxy(20,3);
	printf("|");
	gotoxy(20,4);
	printf("|");
	gotoxy(20,5);
	printf("|");
	gotoxy(20,6);
	printf("|");
	gotoxy(20,7);
	printf("|");
	gotoxy(20,8);
	printf("|");
	gotoxy(20,9);
	printf("|");
	gotoxy(20,10);
	printf("|");
	gotoxy(20,11);
	printf("|");
	gotoxy(20,12);
	printf("|");
	gotoxy(20,13);
	printf("|");
	gotoxy(20,14);
	printf("|");
	gotoxy(20,15);
	printf("|");
	gotoxy(20,16);
	printf("|");



	gotoxy(1,16);
	printf("====================");

	
	return 0;

}
