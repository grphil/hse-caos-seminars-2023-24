#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/wait.h>

int main() {
	char* folder = "./";
	pid_t x = fork();
	if (x == 0) {
		execlp("ls", "asdjkasljkdsa", "-lh", folder, NULL);
		printf("228\n");
		exit(1);
	}
	wait(NULL);
}
