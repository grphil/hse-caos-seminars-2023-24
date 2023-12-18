#include <asm/unistd_32.h>
#include <sys/syscall.h>

void writechar(char x) {
	asm volatile(
		"int $0x80" 
		:
		: "a"(__NR_write), "b"(1), "c"(&x), "d"(1)
	);
}

void sys_exit(int c) {
	asm volatile(
		"int $0x80"
		:
		: "a"(SYS_exit), "b"(c)
	);
}

void _start() {
	writechar('1');
	writechar('a');
	writechar('\n');
	sys_exit(0);
}