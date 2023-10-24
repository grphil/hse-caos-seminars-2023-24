#include <stdio.h>
#include <string.h>

int main() {
	char s[1000];
	scanf("%s", s);
	printf("%s %lu\n", s, strlen(s));
}