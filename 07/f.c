#include <stdio.h>

int main() {
	FILE* fin = fopen("in.txt", "r");

	int a, b;
	fscanf(fin, "%d%d", &a, &b);

	fclose(fin);

	FILE* fout = fopen("out.txt", "w");
	fprintf(fout, "%d\n", a + b);
	fclose(fout);
}