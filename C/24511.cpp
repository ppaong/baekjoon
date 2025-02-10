#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	bool* A = new bool[N];
	int term, count=1;
	for (int i = 0;i < N;i++) {
		cin >> term;
		A[i] = !(bool)term;
	}

	stack<int> S;
	queue<int> Q;
	for (int i = 0;i < N;i++) {
		cin >> term;
		if (A[i])
			S.push(term);
	}
	for (;!S.empty();S.pop())
		Q.push(S.top());

	int M;
	cin >> M;
	for (int i = 0;i < M;i++) {
		cin >> term;
		Q.push(term);
		term = Q.front();
		Q.pop();
		cout << term << " ";
	}
}