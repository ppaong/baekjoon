#include <iostream>
using namespace std;
//11722는 부호 반대로
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int* A = new int[N];
	for (int i = 0;i < N;i++)
		cin >> A[i];

	int* dp = new int[N + 1] {0};
	for (int i = 1;i <= N;i++)
		dp[i] = 100000;
	int M = 1;
	for (int i = 0;i < N;i++) {
		for (int k = 0;k < M;k++) {
			if (dp[k] < A[i]) {
				if (dp[k + 1] > A[i])
					dp[k + 1] = A[i];

				if (k + 1 == M) {
					M++;
					break;
				}			
			}
		}
	}
	cout << M - 1;
}
