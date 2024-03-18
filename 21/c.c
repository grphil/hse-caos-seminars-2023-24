#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include <sys/epoll.h>

char* names[100];

int main() {
	int fd1 = open("c1f", O_RDONLY, 0);
	int fd2 = open("c2f", O_RDONLY, 0);

	int epollfd = epoll_create1(0);

	struct epoll_event ev1, ev2, events[2];

	ev1.events = EPOLLIN;
	ev1.data.fd = fd1;
	epoll_ctl(epollfd, EPOLL_CTL_ADD, fd1, &ev1);
	names[fd1] = "C1";

	ev2.events = EPOLLIN;
	ev2.data.fd = fd2;
	epoll_ctl(epollfd, EPOLL_CTL_ADD, fd2, &ev2);
	names[fd2] = "C2";

	printf("Started\n");

	int opened = 2;
	while (opened > 0) {
		int evcnt = epoll_wait(epollfd, events, 1, -1);
		for (int i = 0; i < evcnt; i++) {
			if (events[i].events != EPOLLIN) {
				printf("closed %s\n", names[events[i].data.fd]);
				epoll_ctl(epollfd, EPOLL_CTL_DEL, events[i].data.fd, NULL);
				opened--;
			} else {
				char buf[4097];
				int n = read(events[i].data.fd, buf, sizeof(buf) - 1);
				buf[n] = '\0';
				printf("%s:\t%s\n", names[events[i].data.fd], buf);
			}
		}
	}
}