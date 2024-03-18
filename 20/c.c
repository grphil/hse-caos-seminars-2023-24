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
	struct sigaction sa;
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = handler;

	sigaction(SIGINT, &sa, NULL);

	while (1) {
		int x;
		int cnt = scanf("%d", &x);
		if (cnt <= 0) {
			printf("Wrong scanf, exit code %d", cnt);
			perror("scanf");
			return 0;
		}
		printf("%d\n", x);
	}
}