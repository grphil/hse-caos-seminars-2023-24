#include <bits/stdc++.h>

using namespace std;

class WaitGroup {
public:
	// Increase counter by count
	void Add(int64_t count) {
		uint32_t t = time.load();
		while (t % 2 == 0 && !time.compare_exchange_weak(t, t + 1));

		int64_t x = c.fetch_add(count);

		if (x + count == 0) {
			while (t % 2 == 1 && !time.compare_exchange_weak(t, t + 1));

			time.notify_all();
		}
	}

	// Wait until counter is zero
	void Wait() {
		uint32_t t = time.load();
		if (t % 2 == 1) {
			time.wait(t);
		}
	}

private:
	atomic<int64_t> c = 0;
	atomic<uint32_t> time = 0;
}