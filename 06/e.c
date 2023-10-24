#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int pasc[n][n];
	int mx = 1;
	pasc[0][0] = 1;
	for (int i = 1; i < n; i++) {
		pasc[0][i] = 0;
		pasc[i][0] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			pasc[i][j] = pasc[i - 1][j] + pasc[i - 1][j - 1];
			if (pasc[i][j] > mx) {
				mx = pasc[i][j];
			}
		}
	}

	int len = 0;
	while (mx > 0) {
		mx /= 10;
		len++;
	}
	if (len % 2 == 0) {
		len += 1;
	}

	for (int i = 0; i < n; i++) {
		printf("%*d ", (n - i) * (len + 1) / 2, 1);
		for (int j = 1; j <= i; j++) {
			printf("%*d ", len, pasc[i][j]);
		}
		printf("\n");
	}
}