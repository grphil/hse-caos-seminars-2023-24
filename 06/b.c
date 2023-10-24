#include <stdio.h>
#include <stdint.h>

int main() {
	int x;
	scanf("%o", &x);
	printf("%013d\n", x);

	double y = 1;
	y /= 3;
	printf("%10lf\n", y);

	int a, b, c;
	scanf("%d:%d:%d", &a, &b, &c);
	printf("%d %d %d\n", a, b, c);
}