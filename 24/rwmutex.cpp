#include <bits/stdc++.h>

using namespace std;

class RWMutex {
public:
	void RLock() {
		while (true) {
			if (state.load() != 0) {
				continue;
			}

			rd.fetch_add(1);

			if (state.load() == 0) {
				break;
			}

			rd.fetch_add(-1);
		}
	}

	void RUnlock() {
		rd.fetch_add(-1);
	}

	void Lock() {
		while (true) {
			int curr_state = state.load();
			if (curr_state == 2) {
				continue;
			}

			if (curr_state == 0) {
				state.compare_exchange_weak(curr_state, 1);
				continue;
			}

			if (rd.load() > 0) {
				continue;
			}

			if (state.compare_exchange_weak(curr_state, 2)) {
				break;
			}
		}
	}

	void Unlock() {
		state.store(0);
	}
private:
	atomic<int> state;
	// 0 - can have new rlocks
	// 1 - no new rlock
	// 2 - write locked
	atomic<uint32_t> rd; // Число читающих
}