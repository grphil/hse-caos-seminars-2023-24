#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>

int main() {
	char node[1000], service[1000];
	scanf("%s%s", node, service);

	struct addrinfo hints = {
		.ai_family = AF_INET,
		.ai_socktype = SOCK_STREAM,
	};
	struct addrinfo* result;

	int err = getaddrinfo(node, service, &hints, &result);

	for (struct addrinfo* a = result; a != NULL; a = a->ai_next) {
		struct sockaddr_in* ip4addr = (struct sockaddr_in*)a->ai_addr;
		printf("%s:%d\n", inet_ntoa(ip4addr->sin_addr), ntohs(ip4addr->sin_port));
	}
	freeaddrinfo(result);
}