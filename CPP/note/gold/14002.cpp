#include <iostream>
#include <vector>
using namespace std;

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
	vector<int>* S = new vector<int>[N + 1];
	for (int i = 1;i <= N;i++)
		dp[i] = 100000;


	int M = 1;
	for (int i = 0;i < N;i++) {
		for (int k = 0;k < M;k++) {
			if (dp[k] < A[i]) {
				if (dp[k + 1] > A[i]) {
					dp[k + 1] = A[i];
					S[k + 1].clear();
					S[k + 1].assign(S[k].begin(), S[k].end());
					S[k + 1].push_back(A[i]);
				}
				if (k + 1 == M) {
					M++;
					break;
				}
			}
		}
	}
	cout << M - 1 << "\n";
	for (int K : S[M - 1])
		cout << K << " ";
}
