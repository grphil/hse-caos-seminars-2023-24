#include <stdio.h>

extern int calc_depth();

int rec(int a) {
	if (a > 0) {
		return rec(a - 1);
	} else {
		return calc_depth();
	}
}

int main() {
	int a;
	scanf("%d", &a);
	a = rec(a);
	printf("%d\n", a);
}