#include <iostream>
#include <deque>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, L;
	cin >> N >> L;

	deque<pair<int,int>> Q;

	int temp;
	for (int i = 0;i < N;i++) {
		cin >> temp;

		if (Q.empty() ? false : i - Q.front().second >= L)
			Q.pop_front();

		for (;Q.empty() ? false : Q.back().first > temp;)
			Q.pop_back();

		Q.push_back(make_pair(temp, i));

		cout << Q.front().first << " ";
	}
}