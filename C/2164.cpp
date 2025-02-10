#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	queue<int> S;
	int N;
	cin >> N;
	for (int i = 1;i <= N;i++)
		S.push(i);

	bool K = false;
	int term;
	for (;!S.empty();) {
		term = S.front();
		if (K)
			S.push(term);

		S.pop();
		K = !K;
	}
	cout << term;
}