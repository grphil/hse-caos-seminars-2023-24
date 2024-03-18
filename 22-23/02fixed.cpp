#include <bits/stdc++.h>

using namespace std;

atomic<int> a = 0;
atomic<int> b = 0;
int x, y;

void f1() {
	a.store(1);
	y = b.load();
}

void f2() {
	b.store(1);
	x = a.load();
}

// a = b + 1
// b = 1

// x, y = {{0, 0}, {0, 1}, {1, 0}, {1, 1}}

int main() {
	for (int i = 0; i < 100'000; i++) {
		if (i % 10000 == 0) {
			cerr << i << endl;
		}
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