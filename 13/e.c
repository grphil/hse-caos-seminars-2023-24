#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

enum {
	BUF_SIZE = 4096
};

int main() {
	int fin = open("in.txt", O_RDONLY);
	int fout = open("out.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);

	char buf[BUF_SIZE];
	ssize_t rd = read(fin, &buf, BUF_SIZE);
	while (rd > 0) {
		ssize_t written = 0;
		while (written < rd) {
			ssize_t wr = write(fout, buf + written, rd - written);
			if (wr < 0) {
				perror("Error while write");
			}
			written += wr;
		}
		rd = read(fin, &buf, BUF_SIZE);
	}
	close(fin);
	close(fout);
}