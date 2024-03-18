#include <bits/stdc++.h>

using namespace std;

int main() {
	int l = -1;
	int r = 1000;
	while (l + 1 < r) {
		int m = (l + r) / 2;
		cout << m << endl;
		char x;
		cin >> x;
		if (x == '<') {
			l = m;
		} else if (x == '>') {
			r = m;
		} else {
			return 0;
		}
	}
}