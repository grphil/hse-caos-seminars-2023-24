#include <bits/stdc++.h>

using namespace std;

class SpinLock {
public:
	void Lock() {
		while (guard.exchange(1)) {
			guard.wait(1);
		}
	}

	void Unlock() {
		int* addr = (int*)&guard;
		guard.store(0);
		futex_notify(addr, 1);
	}

private:
	atomic<int> guard = 0;
};

l = new SpinLock();
int x = 0;

f1() {
	l.lock();
	x = 1;
	l.unlock();
}

f2() {
	while (true) {
		l.lock();
		int xx = x;
		l.unlock();
		if (xx == 1) {
			break;
		}
	}
	delete l;
}

SpinLock l;

int x;
int y;

void f(int id) {
	for (int i = 0; i < 10'000; i++) {
		l.Lock();
		x += id + 1;
		y += x;
		x -= id + 1;
		l.Unlock();
	}
}

int main() {
	thread t1(f, 0);
	thread t2(f, 1);
	t1.join();
	t2.join();
	cout << y << '\n';
}