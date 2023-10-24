#include <unistd.h>
#include <limits.h>
#include <stdio.h>

int main() {
	int* a = sbrk(UINT_MAX);
	// printf("%lu\n", (size_t)a);
	for (int i = 0; i < 10; i++) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}
}