#include <stdio.h>
#include <ctype.h>

int main() {
	int64_t a, b;
	a = 1e18;
	b = 100;
	int64_t c, d;
	asm volatile (
		"mulq %%rcx"
		: "=a" (c)
		, "=d" (d)
		: "a" (a)
		, "c" (b)
	);
	printf("%lld %lld %lld %lld\n", a, b, c, d);
}