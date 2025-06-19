#include <iostream>
#include <vector>
using namespace std;
//memoization
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	bool* L = new bool[N + 1] {false};

	vector<int> S = { 1 };
	vector<int> term;
	L[1] = true;

	int A, B, C, count = 0;
	for (;!L[N];) {
		count++;
		for (int& K : S) {
			A = K + 1;
			B = K + K;
			C = K + K + K;
			if (A <= N) {
				if (!L[A]) {
					L[A] = true;
					term.push_back(A);
				}
			}
			if (B <= N) {
				if (!L[B]) {
					L[B] = true;
					term.push_back(B);
				}
			}
			if (C <= N) {
				if (!L[C]) {
					L[C] = true;
					term.push_back(C);
				}
			}		
		}
		S.clear();
		S.assign(term.begin(), term.end());
		term.clear();
	}
	cout << count;
}