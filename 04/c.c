#include <stdio.h>

extern int ab4(int a, int b); // shuld return a + b * 4

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", ab4(a, b));
}