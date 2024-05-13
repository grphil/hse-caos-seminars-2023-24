#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void* threadFunc(void* arg) {
	printf("Thread started\n");
	fflush(stdout);
	sleep(2);
	printf("Thread finished\n");
	fflush(stdout);
	return NULL;
}

int main() {
	pthread_t threadID;
	pthread_create(&threadID, NULL, threadFunc, NULL);
	sleep(1);
	printf("Main thread\n");
	fflush(stdout);

	pthread_join(threadID, NULL);
	printf("finished\n");
}