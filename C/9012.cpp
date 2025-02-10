#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	stack<bool> S;
	int N;
	cin >> N;
	string term;
	for (int i = 0;i < N;i++) {
		cin >> term;
		for (char C : term) {
			if (C == ')') {
				if (S.empty()) {
					S.push(false);
					break;
				}
				else
					S.pop();
			}
			else
				S.push(true);
		}
		cout << (S.empty() ? "YES" : "NO") << "\n";
		for (;!S.empty();S.pop()) {}
	}
}