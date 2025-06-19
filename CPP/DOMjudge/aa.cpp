#include <iostream>
#include <string>
using namespace std;

int main() {
	string term;
	for (;;) {
		cin >> term;
		if (cin.eof())
			break;

		int a = (term.length() - 1) / 2, b = a + (term.length() - 1) % 2;
		char l = term[a], r = term[b];

		if ((int)l > 90)
			l -= 32;
		if ((int)r > 90)
			r -= 32;

		if (a != b) {
			if (l == r)
				a = 0;
			else if (l > r) {
				l = r;
				a++;
			}
		}
		if (a % 2 != 0)
			l += 32;

		cout << l;
	}
}