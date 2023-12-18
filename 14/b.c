#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum {
	BUF_SIZE = 4096
};

typedef struct F {
	int fd;
	char buf[BUF_SIZE];
	size_t pos; // position in buf
	size_t size; // how much buf is filled
} F;

F* ropen(char* path) {
	int fd = open(path, O_RDONLY);
	if (fd == -1) {
		return NULL;
	}
	F* f = calloc(1, sizeof(F));
	f->fd = fd;
	return f;
}

void rclose(F* f) {
	close(f->fd);
	free(f);
}

bool rflush(F* f) {
	f->pos = 0;
	f->size = 0;
	ssize_t n = read(f->fd, f->buf, BUF_SIZE);
	if (n <= 0) {
		return false;
	} else {
		f->size = n;
		return true;
	}
}

char rget(F* f) {
	if (f->size == f->pos) {
		if (!rflush(f)) {
			return '\0';
		}
	}
	return f->buf[f->pos++];
}

int main() {
	F* f = ropen("in.txt");
	char c;
	while ((c = rget(f)) != '\0') {
		printf("%c", c);
	}
	rclose(f);
}