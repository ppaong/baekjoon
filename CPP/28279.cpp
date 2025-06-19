#include <iostream>
#include <deque>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	deque<int> S;
	int N;
	cin >> N;
	int term;
	for (int i = 0;i < N;i++) {
		cin >> term;
		switch (term) {
		case 1:
			cin >> term;
			S.push_front(term);
			break;
		case 2:
			cin >> term;
			S.push_back(term);
			break;
		case 3:
			if (!S.empty()) {
				cout << S.front() << "\n";
				S.pop_front();
			}
			else
				cout << "-1\n";
			break;
		case 4:
			if (!S.empty()) {
				cout << S.back() << "\n";
				S.pop_back();
			}
			else
				cout << "-1\n";
			break;
		case 5:
			cout << S.size() << "\n";
			break;
		case 6:
			cout << (S.empty() ? 1 : 0) << "\n";
			break;
		case 7:
			cout << (S.empty() ? -1 : S.front()) << "\n";
			break;
		case 8:
			cout << (S.empty() ? -1 : S.back()) << "\n";
			break;
		}
	}
}
