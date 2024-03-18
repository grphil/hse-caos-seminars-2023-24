#include <bits/stdc++.h>

using namespace std;

class AtomicCounter {
public:
	AtomicCounter() {
		for (int i = 0; i < 800; i++) {
			c[i] = 0;
		}
	}

	void Add(int id) {
		c[id * 100].fetch_add(1);
	}

	int Get() {
		int res = 0;
		for (auto& x : c) {
			res += x.load();
		}
		return res;
	}

private:
	array<atomic<int>, 800> c;
};

AtomicCounter c;

void singleRun(int id) {
	for (int i = 0; i < 1000'000; i++) {
		c.Add(id);
	}
}

void test() {
	vector<thread> t(8);
	for (int i = 0; i < 8; i++) {
		t[i] = thread(singleRun, i);
	}
	for (int i = 0; i < 8; i++) {
		t[i].join();
	}
	cerr << c.Get() << endl;
}

int main() {
	for (int i = 0; i < 10; i++) {
		auto start = chrono::steady_clock::now();
		test();
		auto elapsed = chrono::steady_clock::now() - start;

		cerr << "Time elapsed: " << chrono::duration_cast<chrono::milliseconds>(elapsed) << endl;
	}
}