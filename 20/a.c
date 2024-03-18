#include <sys/mman.h>

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
	int fd = open("in.txt", O_RDWR, 0777);
	off_t sz = lseek(fd, 0, SEEK_END);
	char* ptr = mmap(0, sz, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	ptr[0] = 'x';
	munmap(ptr, sz);
	// strncpy(s, ptr, 4);
	// s[4] = '\0';
	// printf("%s\n", s);
}