#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Once {
public:
	Once(function<T*()> get) 
		: getter(get)
	{}

	~Once() {
		delete val;
	}

	T* Get() {
		auto v = val.load();
		if (v == nullptr) {
			lock_guard l(m);
			if (val == nullptr) {
				val = getter();
			}
			v = val;
		}
		return v;
	}

private:
	function<T*()> getter;

	mutex m;
	atomic<T*> val = nullptr;
};