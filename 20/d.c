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
	sigset_t signals, old;
	sigemptyset(&signals);
	sigaddset(&signals, SIGINT);

	struct sigaction sa;
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = handler;

	sigaction(SIGINT, &sa, NULL);

	while (1) {
		sigprocmask(SIG_BLOCK, &signals, &old);
		printf("aaa\n");
		sleep(3);
		printf("bbb\n");
		sigprocmask(SIG_SETMASK, &old, NULL);
	}
}