#include <stdio.h>

void aaaa() {
	printf("aaaaa\n");
}

int A;
extern void inc_a();

int main() {
	scanf("%d", &A);
	inc_a();
	printf("%d\n", A);
}