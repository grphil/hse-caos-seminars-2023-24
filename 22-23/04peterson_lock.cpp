#include <bits/stdc++.h>

using namespace std;

class PetersonLock {
public:
	PetersonLock() {
		want[0] = 0;
		want[1] = 0;
	}

	void Lock(int id) {
		want[id].store(true);
		victim.store(id);
		while (want[1 - id].load() && victim.load() == id);
	}

	void Unlock(int id) {
		want[id].store(false);
	}
private:
	array<atomic<bool>, 2> want;
	atomic<int> victim;
};

PetersonLock l;

int x;
int y;

void f(int id) {
	for (int i = 0; i < 10'000; i++) {
		l.Lock(id);
		x += id + 1;
		y += x;
		x -= id + 1;
		l.Unlock(id);
	}
}

int main() {
	thread t1(f, 0);
	thread t2(f, 1);
	t1.join();
	t2.join();
	cout << y << '\n';
}