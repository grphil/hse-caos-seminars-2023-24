#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdatomic.h>

int counter = 0;
int data = 0;

typedef _Atomic int spinlock;

void spinlock_lock(spinlock* s) {
	while (atomic_exchange(s, 1)) {
		// asm volatile ("pause");
	}
}

void spinlock_unlock(spinlock* s) {
	atomic_store(s, 0);
}

spinlock m;

void* threadFunc(void* arg) {
	for (int i = 0; i < 10000; i++) {
		spinlock_lock(&m);
		data = 2;
		counter += data;
		spinlock_unlock(&m);
	}
	return NULL;
}

int main() {
	pthread_t threadID;
	pthread_create(&threadID, NULL, threadFunc, NULL);

	for (int i = 0; i < 10000; i++) {
		spinlock_lock(&m);
		data = 1;
		counter += data;
		spinlock_unlock(&m);
	}

	pthread_join(threadID, NULL);
	printf("%d\n", counter);
}