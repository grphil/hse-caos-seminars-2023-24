#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include <sys/wait.h>

int fd1[2];
int fd2[2];	

void cl() {
	close(fd1[0]);
	close(fd2[0]);
	close(fd1[1]);
	close(fd2[1]);
}

int main() {
	pipe(fd1);
	pipe(fd2);
	if (!fork()) {
		dup2(fd1[1], 1);
		dup2(fd2[0], 0);
		cl();
		execlp("./bs", "bs", NULL);
		exit(1);
	}
	if (!fork()) {
		dup2(fd1[0], 0);
		dup2(fd2[1], 1);
		cl();
		execlp("./binsearch", "binsearch", NULL);
		exit(1);
	}
	cl();
	wait(NULL);
	wait(NULL);
}