#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid;

int bLoop = 1;

void *doSomeTing(void *arg)
{
	char ch = getchar();
	while(1)
	{	
		ch = getchar();
		if(ch == 'q') {
			bLoop = 0;
		}

	}
	return NULL;

}

int main()
{
	int err;
	err = pthread_create(&tid,NULL,&doSomeTing,NULL);
	if(err != 0) {
		printf("\r\ncannot created thread : [%s] \r\n",strerror(err));
	}
	else {
		printf("\r\nThread successfully \r\n");
	}

	while(bLoop) {
		puts("test");
		sleep(1);
	}

	printf("bye \r\n");

	return 0;
}
