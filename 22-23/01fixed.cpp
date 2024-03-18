#include <bits/stdc++.h>

using namespace std;

atomic<int> a = 0;

void f() {
	a.fetch_add(1);
}

int main() {
	for (int i = 0; i < 10'000; i++) {
		thread t1(f);
		thread t2(f);
		t1.join();
		t2.join();
	}
	cout << a << '\n';
}