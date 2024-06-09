#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdatomic.h>

long long counter = 0;
int data = 0;

typedef _Atomic int spinlock;

void mutex_lock(spinlock* m) {
	while (atomic_exchange(m, 1) == 1) {
		// asm volatile ("pause");
	}
}

void mutex_unlock(spinlock* m) {
	atomic_store(m, 0);
}

spinlock m = 0;

void* threadFunc(void*) {
	for (int i = 0; i < 100000; i++) {
		mutex_lock(&m);
		data = i;
		counter += data;
		mutex_unlock(&m);
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
}