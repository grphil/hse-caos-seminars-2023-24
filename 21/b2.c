#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
	FILE* f = fopen("bf", "w");
	printf("opened\n");
	fflush(stdin);
	char buf[1000];
	scanf("%s", buf);
	fprintf(f, "%s\n", buf);
	fclose(f);
}