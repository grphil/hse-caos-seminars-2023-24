#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include <sys/wait.h>

int main() {
	pid_t x = fork();
	if (x == 0) {
		int fd = open("c.c", O_RDONLY, 0);
		dup2(fd, 0);
		close(fd);
		execlp("wc", "wc", "-l", NULL);
		// unreachable
		exit(1);
	}
	wait(NULL);
}