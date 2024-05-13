#include "../a.h"
#include <iostream>

using namespace std;

int main() {
	if (a(2) == 4) {
		cout << "GOOD" << endl;
		return 0;
	} else {
		cerr << "BAD" << endl;
		return 1;
	}
}