#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
	unsigned hours : 5;
	unsigned minutes : 9;
	unsigned seconds : 9;
} time;

int main() {
	printf("%lu\n", sizeof(time));
}