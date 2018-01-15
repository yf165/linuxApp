#include <stdio.h>
#include <string.h>
#include <pthread.h>
#define BUFSIZE 200
char buf[BUFSIZE] = {0};

int main(void)
{
	printf("please input the characters\n");
	pthread_t subThread;
	
	while(1){
		scanf("%s",buf);
		printf("your input:%s\n",buf);
		if (strncmp(buf,"end",3) == 0){
			break;
		}
	}
	return  0;
}