#include <stdio.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);
	char s[n + 1];
	scanf("%s", s);
	char* ss = s + 1;
	printf("%s %lu\n", ss, strlen(s));
}