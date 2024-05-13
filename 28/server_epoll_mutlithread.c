#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <netdb.h>
#include <stdbool.h>
#include <sys/epoll.h>
#include <pthread.h>

int create_listener(char* service) {
	struct addrinfo hints = {
		.ai_family = AF_INET,
		.ai_socktype = SOCK_STREAM,
		.ai_flags = AI_PASSIVE,
	};
	struct addrinfo* result;

	int err = getaddrinfo(NULL, service, &hints, &result);

	int sock = -1;
	for (struct addrinfo* a = result; a != NULL; a = a->ai_next) {
		sock = socket(a->ai_family, a->ai_socktype, 0);

		if (sock < 0) {
			perror("socket");
			continue;
		}

		if (bind(sock, a->ai_addr, a->ai_addrlen) < 0) {
			perror("bind");
			close(sock);
			sock = -1;
			continue;
		}

		if (listen(sock, SOMAXCONN) < 0) {
			perror("listen");
			close(sock);
			sock = -1;
			continue;
		}

		break;
	}
	freeaddrinfo(result);

	return sock;
}

int epollfd;
int sock;

void* run_server_thread(void* argv) {
	long tid = (long)argv;
	while (true) {
		struct epoll_event event;
		epoll_wait(epollfd, &event, 1, -1); 

		if (event.data.fd == sock) {
			int afd = accept(sock, NULL, NULL);
			if (afd < 0) {
				continue;
			}
			struct epoll_event new_conn = {
				.events = EPOLLIN | EPOLLONESHOT,
				.data.fd = afd
			};
			epoll_ctl(epollfd, EPOLL_CTL_ADD, afd, &new_conn);

			event.events = EPOLLIN | EPOLLONESHOT;
			epoll_ctl(epollfd, EPOLL_CTL_MOD, event.data.fd, &event);
		} else {
			int afd = event.data.fd;

			char buf[1000];
			int sz = read(afd, buf, 100);
			if (sz == 0) {
				close(afd);

				epoll_ctl(epollfd, EPOLL_CTL_DEL, afd, NULL);
			} else {
				buf[sz] = '\0';
				printf("thread %ld read %d bytes: %s", tid, sz, buf);

				event.events = EPOLLIN | EPOLLONESHOT;
				epoll_ctl(epollfd, EPOLL_CTL_MOD, event.data.fd, &event);
				sleep(5);
			}
		}
	}
	return NULL;
}

int main(int argc, char** argv) {
	sock = create_listener(argv[1]);

	if (sock < 0) {
		return 1;
	}

	epollfd = epoll_create1(0);

	struct epoll_event add_sock = {
		.events = EPOLLIN | EPOLLONESHOT,
		.data.fd = sock
	};

	epoll_ctl(epollfd, EPOLL_CTL_ADD, sock, &add_sock);

	pthread_t tid;
	pthread_create(&tid, NULL, run_server_thread, (void*)1);
	run_server_thread((void*)0);
}
