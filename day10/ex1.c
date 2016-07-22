#include <stdio.h>

void draw_line(int n,char c)
{
	for(int i=0;i<n;i++) {
		putchar(c);
	}
}

void draw_tril()
{
	int ix,iy;
	for(iy=10;iy>0;iy--) {
		for(ix=0;ix<iy;ix++) {
			putchar('*');
		}
		puts("");
	}
}

void draw_tril2()
{
	int ix,iy;
	for(iy=0;iy<10;iy++) {
		draw_line(9-iy,' ');
		draw_line(iy,'*');
		puts("");
	}

}

void draw_tril3()
{
	int ix,iy;
	for(iy=0;iy<10;iy++) {
		draw_line(9-iy,' ');
		draw_line((iy*2)-1,'*');
		puts("");
	}	
	for(iy = 0;iy<5;iy++) {
		draw_line(3,' ');
		draw_line(11,'*');
		puts("");

	}

	

}

int main()
{	
	draw_tril();
	draw_tril2();
	draw_tril3();
	return 0;
}
