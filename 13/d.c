#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int fd = open("in.txt", O_RDONLY);
	char buf[11];
	ssize_t rd = read(fd, &buf, 10);
	while (rd > 0) {
		buf[rd] = '\0';
		printf("%ld %s\n", rd, buf);
		rd = read(fd, &buf, 10);
	}

	printf("ENDED\n");
	
	lseek(fd, 5, SEEK_SET);
	rd = read(fd, &buf, 10);
	while (rd > 0) {
		buf[rd] = '\0';
		printf("%ld %s\n", rd, buf);
		rd = read(fd, &buf, 10);
	}
	close(fd);
}