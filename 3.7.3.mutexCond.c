#include <stdio.h>
#include <string.h>
#include <pthread.h>
#define BUFSIZE 200
#include <pthread.h>

char buf[BUFSIZE] = {0};
pthread_mutex_t mutex;
pthread_cond_t cond;
void *funcForSubThread(void *arg)
{
	 while(1){
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&cond,&mutex);
		printf("input length:%d\n",strlen(buf));
		pthread_mutex_unlock(&mutex);
		if (strncmp(buf,"end",3) == 0){
			break;
		}
	 }
}
int main(void)
{
	printf("please input the characters\n");
	pthread_t subThread;
	int ret = -1;
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond,NULL);
	pthread_create(&subThread,NULL,funcForSubThread,NULL);
	while(1){
		scanf("%s",buf);
		printf("your input:%s\n",buf);
		pthread_cond_signal(&cond);
		if (strncmp(buf,"end",3) == 0){
			break;
		}
	}
	printf("waiting to subThread\n");
	ret = pthread_join(subThread,NULL);
	printf("subthread finish\n");
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
	return  0;
}