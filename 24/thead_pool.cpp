#include <bits/stdc++.h>

using namespace std;

using func = std::function<void()>;

class ThreadPool {
public:
	ThreadPool(size_t n) {
		for (size_t i = 0; i < n; i++) {
			t.emplace_back([this](){
				run_thread();
			});
		}
	}

	void add(func f) {
		unique_lock lock(m);
		queue.emplace_back(f);
		v.notify_one();
	}

	void finish() {
		{
			unique_lock lock(m);
			finished = true;
		}
		v.notify_all();
		for (auto& thread : t) {
			thread.join();
		}
	}


private:
	deque<func> queue;
	vector<thread> t;
	bool finished = false;
	condition_variable v;
	mutex m;
	
	void run_thread() {
		while (true) {
			func f;
			{
				unique_lock lock(m);
				while (queue.empty() && !finished) {
					v.wait(m);
				}

				if (queue.empty() && finished) {
					break;
				}

				f = std::move(queue.front());
				queue.pop_front();
			}
			f();
		}
	}
}