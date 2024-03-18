#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int signo) {
	printf("finished after signal %d\n", signo);
	exit(0);
}

int main() {
	struct sigaction sa;
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = handler;

	sigaction(SIGINT, &sa, NULL);

	while (1) {
		sleep(1);
		printf("228\n");
	}
}