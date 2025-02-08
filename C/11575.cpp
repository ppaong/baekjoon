#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int A, B;
	string term;
	for (int i = 0;i < N;i++) {
		cin >> A >> B >> term;
		for (string::iterator iter = term.begin();iter != term.end();iter++) {
			cout << (char)((A * ((int)*iter - 65) + B) % 26 + 65);
		}
		cout << "\n";
	}
}