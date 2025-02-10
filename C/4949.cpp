#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	stack<char> S;
	string term;
	bool loop = true;
	for (;;) {
		getline(cin, term);
		if (term == ".")
			return 0;

		term.pop_back();
		for (char& C : term) {
			if (C == '(' || C == '[')
				S.push(C);
			else if (C == ')') {
				if (S.empty()) {
					S.push(C);
					break;
				}
				else if (S.top() == '[')
					break;
				else if (S.top() == '(')
					S.pop();
			}
			else if (C == ']') {
				if (S.empty()) {
					S.push(C);
					break;
				}
				else if (S.top() == '(')
					break;
				else if (S.top() == '[')
					S.pop();
			}
		}
		cout << (S.empty() ? "yes\n" : "no\n");
		for (;!S.empty();S.pop()) {}
	}
}
