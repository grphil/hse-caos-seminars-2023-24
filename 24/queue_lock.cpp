#include <bits/stdc++.h>

using namespace std;

class QueueLock {
public:
	class Guard {
		friend class QueueLock;
	public:
		Guard(QueueLock& lock) : l(lock) {
			l.Lock(this);
		}

		~Guard() {
			l.Unlock(this);
		}

	private:
		QueueLock& l;
		atomic<bool> locked = false;
		atomic<Guard*> next = nullptr;
	}

private:
	atomic<Guard*> latest = nullptr;

	void Lock(Guard* g) {
		auto old = latest.exchange(g);

		if (old == nullptr) {
			return;
		}

		old->next.store(g);

		while (g->locked.load() == false) {
			g->locked.wait(false);
		}
	}

	void Unlock(Guard* g) {
		auto curr = g;

		if (latest.compare_exchange_strong(curr, nullptr)) {
			return;
		}

		while (g->next.load() == nullptr);

		g->next.load()->locked.store(true);
		g->next.load()->locked.notify_one();
	}
}

int cnt;
QueueLock l;

void Addcnt() {
	QueueLock::Guard g(l);
	cnt++;
}

int main() {

}