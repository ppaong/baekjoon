#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int** S = new int* [N];
	for (int i = 0;i < N;i++) {
		S[i] = new int[i + 1];
		for (int j = 0;j <= i;j++)
			cin >> S[i][j];
	}

	if (N == 1) {
		cout << S[0][0];
		return 0;
	}

    //top bottom
	int** dp = new int* [N];
	dp[0] = new int[1];
	dp[0][0] = S[0][0];

	for (int i = 1;i < N;i++) {
		dp[i] = new int[i + 1];
		dp[i][0] = S[i][0] + dp[i - 1][0];
		for (int j = 1;j < i;j++)
			dp[i][j] = S[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
		dp[i][i] = S[i][i] + dp[i - 1][i-1];
	}

	int M = dp[N - 1][0];
	for (int i = 1;i < N;i++)
		if (dp[N - 1][i] > M)
			M = dp[N - 1][i];
	cout << M;
}
