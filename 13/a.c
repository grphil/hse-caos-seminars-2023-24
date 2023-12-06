#include <stdio.h>

extern void mulab(double a, double b, double* res);

int main() {
	double a, b, c;
	scanf("%lf%lf", &a, &b);
	mulab(a, b, &c);
	printf("%lf\n", c);
}