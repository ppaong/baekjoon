#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	string term;
	for (int i = 666;i < 3000666;i++) {
		term = to_string(i);
		if (term.find("666") != string::npos) {
			if (--N <= 0) {
				cout << i;
				break;
			}
		}
	}
}
