#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

void* threadFunc(void* arg) {
	size_t x = *(size_t*)(arg);
	size_t res = 0;
	for (size_t i = 0; i < 1000000000; i++) {
		res += x + i;
	}
	return (void*)(res);
}

int main() {
	pthread_t t1, t2;
	size_t x1 = 1;
	size_t x2 = 2;
	pthread_create(&t1, NULL, &threadFunc, (void*)(&x1));
	pthread_create(&t2, NULL, &threadFunc, (void*)(&x2));

	size_t res1 = 0;
	size_t res2 = 0;

	pthread_join(t1, (void**)(&res1));
	pthread_join(t2, (void**)(&res2));
	printf("%lu %lu", res1, res2);
}