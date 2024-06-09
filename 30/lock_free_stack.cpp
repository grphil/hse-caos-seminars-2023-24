#include <bits/stdc++.h>

using namespace std;

// This is not correct

template<typename T>
class Stack {
public:
	void Push(T* x) {
		auto new_head = new Node{x, nullptr};
		while (true) {
			if (head.compare_exchange_weak(new_head->next, new_head)) {
				return;
			}
		}
	}

	T* Pop() {
		while (true) {
			auto old_head = head.load();

			if (old_head == nullptr) {
				return nullptr;
			}

			if (head.compare_exchange_weak(old_head, old_head->next)) {
				T* value = old_head->value;
				delete old_head;
				return value;
			}
		}
	}

private:
	struct Node {
		T* x;
		Node* next;
	};

	atomic<Node*> head = nullptr;
}