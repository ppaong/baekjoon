#include <iostream>
#include <string>
using namespace std;

int main() {
	int term;
	cin >> term;
	int N = term;
	bool plus = N < 2;
	string S = (plus ? "ascending" : "descending");
	for (int i = 1;i < 8;i++) {
		cin >> term;
		if (N + (plus ? i : -i) != term) {
			S = "mixed";
			break;
		}
	}
	cout << S;
}