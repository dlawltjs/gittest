#include <stdio.h>
#include <stdlib.h>
#include "../engine2d.h"

int main()
{
	system("clear");
	
	int i=0;
	int a=0;
	int b=9;

	while(i<9) {
		gotoxy(20,i+10);
		printf("+");
		gotoxy(i+16,14);
		printf("+ ");
		i++;
	}

	while(a<9 && b>0){
		gotoxy(a,a);
		printf("*");
		a++;
		gotoxy(b,a);
		printf("*");
		b--;

	}




	gotoxy(0,30);
	printf("==================================");
	return 0;
}
