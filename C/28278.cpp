#include <iostream>
#include <stack>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	stack<int> S;
	int term;
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> term;
		switch (term) {
		case 1:
			cin >> term;
			S.push(term);
			break;
		case 2:
			if (S.empty())
				cout << "-1\n";
			else {
				cout << S.top() << "\n";
				S.pop();
			}
			break;
		case 3:
			cout << S.size() << "\n";
			break;
		case 4:
			cout << (S.empty() ? "1\n" : "0\n");
			break;
		case 5:
			cout << (S.empty() ? -1 : S.top()) << "\n";
			break;
		default:
			break;
		}
	}
}
