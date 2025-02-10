#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	queue<int> S;
	string term;
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> term;
		switch (term[0]) {
		case 'p':
			if (term[1] == 'u') {
				int K;
				cin >> K;
				S.push(K);
			}
			else {
				if (!S.empty()) {
					cout << S.front() << "\n";
					S.pop();
				}
				else
					cout << "-1\n";
			}
			break;
		case 's':
			cout << S.size() << "\n";
			break;
		case 'e':
			cout << (S.empty() ? "1\n" : "0\n");
			break;
		case 'f':
			cout << (S.empty() ? -1 : S.front()) << "\n";
			break;
		case 'b':
			cout << (S.empty() ? -1 : S.back()) << "\n";
			break;
		}
	}
}
