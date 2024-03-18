#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
	FILE* f = fopen("c1f", "w");
	char buf[1000];
	while (1) {
		scanf("%s", buf);
		fprintf(f, "%s", buf);
		fflush(f);
	}
	fclose(f);
}