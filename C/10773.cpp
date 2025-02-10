#include <iostream>
#include <stack>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	stack<int> S;
	int N;
	cin >> N;
	int K;
	for (int i = 0;i < N;i++) {
		cin >> K;
		if (K == 0)
			S.pop();
		else
			S.push(K);
	}
	int sum=0;
	for (;!S.empty();S.pop())
		sum += S.top();
	cout << sum;
}