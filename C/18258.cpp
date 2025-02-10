#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	queue<int> Q;
	int N;
	cin >> N;
	string term;
	int K;
	for (int i = 0;i < N;i++) {
		cin >> term;
		switch (term[0]) {
		case'p':
			if (term[1] == 'u') {
				cin >> K;
				Q.push(K);
			}
			else {
				if (Q.empty())
					cout << "-1\n";
				else {
					cout << Q.front() << "\n";
					Q.pop();
				}
			}
			break;
		case's':
			cout << Q.size() << "\n";
			break;
		case'e':
			cout << (Q.empty() ? 1 : 0) << "\n";
			break;
		case'f':
			cout << (Q.empty() ? -1 : Q.front()) << "\n";
			break;
		case'b':
			cout << (Q.empty() ? -1 : Q.back()) << "\n";
			break;
		}
	}
}