#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

void* threadFunc(void* arg) {
	printf("Start of thread\n");
	fflush(stdout);
	sleep(2);
	printf("End of thread\n");
	fflush(stdout);
	return NULL;
}

int main() {
	pthread_t threadID;
	pthread_create(&threadID, NULL, &threadFunc, NULL);

	sleep(1);
	printf("Main function\n");
	fflush(stdout);

	pthread_join(threadID, NULL);
	printf("Finished\n");
}