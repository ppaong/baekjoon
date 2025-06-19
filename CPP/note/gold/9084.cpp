#include <iostream>
using namespace std;

#define max(a,b) (a>b?a:b)

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	int V[21];
	long long A[10001];
	long long B[10001];
	long long* dp[21];

	for (;T > 0;T--) {
		int N, K;
		cin >> N;
		for (int i = 0;i < N;i++)
			cin >> V[i];
		cin >> K;

		dp[0] = A;
		for (int j = 0;j <= K;j++)
			dp[0][j] = 0;
		for (int j = V[0];j <= K;j += V[0])
			dp[0][j] = 1;
		dp[1] = B;

		for (int i = 1;i < N;i++) {	
			for (int j = 0;j < V[i];j++)
				dp[i][j] = dp[i - 1][j];
			for (int j = V[i];j <= K;j++)
				dp[i][j] = max(dp[i - 1][j] + dp[i][j - V[i]], dp[i - 1][j] + (j % V[i] == 0 ? 1 : 0));
			dp[i + 1] = dp[i - 1];
		}
		cout << dp[N - 1][K] << "\n";
	}
}