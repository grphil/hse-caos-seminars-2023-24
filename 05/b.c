#include <stdio.h>

extern int calc_depth();

int rec(int a) {
	if (a <= 1) {
		return calc_depth();
	}
	if (a % 2 == 0) {
		return rec(a / 2);
	} else {
		return rec(a * 3 + 1);
	}
}

int main() {
	int a;
	scanf("%d", &a);
	a = rec(a);
	printf("%d\n", a);
}