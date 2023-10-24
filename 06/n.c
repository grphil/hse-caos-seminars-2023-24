#include <stdio.h>
#include <string.h>

void make_good(char* s) {
	char* l = s;
	for (char* r = s; *r != '\0'; r++) {
		if (*r != 'z') {
			*l = *r;
			l++;
		}
	}
	*l = '\0';
}

int main() {
	char s[10000];
	scanf("%s", s);
	printf("%lu\n", strlen(s));
	make_good(s);
	printf("%s %lu\n", s, strlen(s));

}