#include <bits/stdc++.h>

using namespace std;

int a = 0;
int b = 0;
int x, y;

void f1() {
	a = 1;
	y = b;
}

void f2() {
	b = 1;
	x = a;
}

a = b + 1
b = 1

// x, y = {{0, 0}, {0, 1}, {1, 0}, {1, 1}}

int main() {
	for (int i = 0; i < 10'000; i++) {
		a = 0;
		b = 0;
		thread t1(f1);
		thread t2(f2);
		t1.join();
		t2.join();
		if (x == 0 && y == 0) {
			cout << "CPU is broken\n";
			return 0;
		}
	}
}