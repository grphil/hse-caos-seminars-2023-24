#include <stdio.h>

extern int pipe(int n, int a, ...);

int inc(int a) {
	return a + 1;
}

int sum(int a) {
	return a - 1;
}

int div2(int a) {
	return a / 2;
}

int main() {
	int a = 228;
	int b = pipe(5, a, inc, sum, inc, div2, inc);
	printf("%d\n", b);
}

