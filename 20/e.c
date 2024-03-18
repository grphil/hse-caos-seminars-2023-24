#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int cnt = 0;

void handler(int signo) {
	cnt++;
	if (cnt <= 3) {
		printf("I will not die\n");
	} else {
		printf("finished after signal %d\n", signo);
		exit(0);
	}
}

int main() {
	int x = fork();
	if (x == 0) {
		struct sigaction sa;
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = handler;

		sigaction(SIGINT, &sa, NULL);
		while (1) {
			printf("228\n");
			sleep(1);
		}
	} else {
		for (int i = 0; i < 4; i++) {
			sleep(2);
			kill(x, SIGINT);
		}
	}
}