#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/wait.h>

int main() {
	int xx = 1;
	pid_t x = fork();
	if (x == 0) {
		xx = 2;
		printf("child\n");
		exit(0);
	} else {
		wait(NULL);
		printf("parent, child id: %d\n", x);
		printf("%d\n", xx);
	}
}