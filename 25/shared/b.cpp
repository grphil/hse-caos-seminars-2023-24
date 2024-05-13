#include <dlfcn.h>

#include <iostream>

using namespace std;

int main() {
	void* liba = dlopen("liba.so", RTLD_NOW);

	if (liba == NULL) {
		return 1;
	}

	int (*f)(int, int);

	string command;
	int a, b;

	cin >> command >> a >> b;

	f = (int (*)(int, int))dlsym(liba, command.c_str());

	if (f == NULL) {
		cout << "NO symbol " << command << endl;
		return 1;
	}

	int c = f(a, b);
	cout << c << endl;
}