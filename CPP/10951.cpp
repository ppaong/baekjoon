#include <iostream>
using namespace std;

int main() {
	int A, B;
	for (;;) {
		cin >> A >> B;
		if (cin.eof()) break;
		cout << A + B << "\n";
	}
}