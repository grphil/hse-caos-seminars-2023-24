#include <bits/stdc++.h>

using namespace std;

template<typename T, size_t Capacity>
class Queue {
public:
	bool Push(T* item) {
		size_t h = head.load();
		size_t t = tail.load();
		if (h - t >= Capacity) {
			return false;
		}
		buf[h % Capacity].store(item);
		head.fetch_add(1);
		return true;
	}

	T* Pop() {
		while (true) {
			size_t h = head.load();
			size_t t = tail.load();
			if (t == h) {
				return nullptr;
			}
			T* val = buf[t % Capacity].load();
			if (tail.compare_exchange(t, t + 1)) {
				return val;
			}
		}
	}

private:
	std::array<atomic<T*>, Capacity> buf;
	atomic<size_t> head = 0;
	atomic<size_t> tail = 0;
};