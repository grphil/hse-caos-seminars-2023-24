#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include <sys/wait.h>

int main() {
	int fd[2];
	pipe(fd);
	if (!fork()) {
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		execlp("ls", "ls", "-l", "./", NULL);
	}
	close(fd[1]);
	if (!fork()) {
		dup2(fd[0], 0);
		close(fd[0]);
		execlp("wc", "wc", "-l", NULL);
	}
	close(fd[0]);
	wait(NULL);
	wait(NULL);
}