#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
	FILE* f = fopen("bf", "r");
	printf("opened\n");
	fflush(stdin);
	char buf[1000];
	fscanf(f, "%s", buf);
	printf("%s\n", buf);
	fclose(f);
}