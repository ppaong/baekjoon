#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	queue<int> S;
	queue<int> Y;
	int N, K;
	cin >> N >> K;
	int count = 1;
	for (int i = 1;i <= N;i++) {
		if (count >= K) {
			Y.push(i);
			count = 1;
		}
		else {
			S.push(i);
			count++;
		}
	}
	for (;!S.empty();S.pop()) {
		if (count >= K) {
			Y.push(S.front());
			count = 1;
		}
		else {
			S.push(S.front());
			count++;
		}
	}

	cout << "<" << Y.front();
	Y.pop();
	for (;!Y.empty();Y.pop())
		cout << ", " << Y.front();
	cout << ">";
}