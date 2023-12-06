#include <stdio.h>

extern float minsq(float a, float b);

int main() {
	float a, b;
	scanf("%f%f", &a, &b);
	printf("%lu\n", sizeof(long double));
	printf("%f\n", minsq(a, b));
}

