#include <bits/stdc++.h>

using namespace std;

int main() {
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	int x;
	fin >> x;
	while (true) {
		int a;
		cin >> a;
		fout << a << endl;
		if (x < a) {
			cout << ">" << endl;
		} else if (x > a) {
			cout << "<" << endl;
		} else {
			cout << "=" << endl;
			return 0;
		}
	}
}