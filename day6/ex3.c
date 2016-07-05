#include <stdio.h>

int main()
{
	char astr[] = "world";
	char *pstr = "hello";

	printf("%s %s \r\n",astr,pstr);
	
	pstr = astr;

	printf("%s \r\n",pstr);

	//astr = pstr; 실행 안되는 명령어!
	
	//배열은 상수값. 주소 넣을수 없다~
	//포인터는 주소 넣을 수 있다!


}
