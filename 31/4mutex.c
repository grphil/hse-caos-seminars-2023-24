#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdatomic.h>

pthread_mutex_t mutex;
pthread_once_t once = PTHREAD_ONCE_INIT;

long long counter = 0;
int data = 0;

void mutex_init() {
	pthread_mutex_init(&mutex, NULL);
}

void* threadFunc(void*) {
	pthread_once(&once, mutex_init);
	for (int i = 0; i < 100000; i++) {
		pthread_mutex_lock(&mutex);
		data = i;
		counter += data;
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main() {
	pthread_t t1, t2;
	pthread_create(&t1, NULL, &threadFunc, NULL);
	pthread_create(&t2, NULL, &threadFunc, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("%lld\n", counter);

	pthread_mutex_destroy(&mutex);
}