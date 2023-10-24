#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main() {
	int res = 0;
	int c;

	while ((c = getchar()) != EOF) {
		if (isspace(c)) {
			res++;
		}
	}
	printf("%d\n", res);
}