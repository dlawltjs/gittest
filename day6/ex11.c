#include <stdio.h>
#include <string.h>

int ext_sum = 0; //정적 메모리공간에 할당(스택x)


void test()
{
	static int sum = 0; //정적인 공간에 값을 보존. 함수 안에서만 사용가능
	sum++;
	printf("%d \r\n",sum);
	
	ext_sum++;

}

extern int test_num; //외부변수

int main()
{
	test();	
	test();

	printf("%d \r\n",ext_sum);
	
	printf("%d \r\n",test_num);

	//printf("%d", sum); // 오류:값이 호출 안됨

	return 0;
}
