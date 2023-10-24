#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
#include <string.h>

char err_msg[100];
jmp_buf* ebuf;

#define try do { \
	jmp_buf env_buf; \
	jmp_buf* old_buf = ebuf; \
	ebuf = &env_buf; \
	if (setjmp(env_buf) == 0) {

#define catch ebuf = old_buf; \
	} else { \
		ebuf = old_buf;

#define endtry }} while(0);

void throw(char* err) {
	strcpy(err_msg, err);
	longjmp(*ebuf, 1);
}

char* get_err() {
	return err_msg;
}

int main() {
	try {
		printf("Start\n");
		try {
			printf("second try\n");
			throw("1");
			printf("228\n");
		} catch {
			printf("Got err in second try: %s\n", get_err());
			throw("3");
		} endtry
		throw("2");
	} catch {
		printf("First try error: %s\n", get_err());
	} endtry
}