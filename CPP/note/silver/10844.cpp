#include <iostream>
using namespace std;
//경우의 수를 쓰는 다른방법이 있어보임
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int** dp = new int* [N + 1];
	dp[1] = new int[10];
	dp[1][0] = 0;
	for (int i = 1;i <= 9;i++)
		dp[1][i] = 1;

	for (int i = 2;i <= N;i++) {
		dp[i] = new int[10];
		dp[i][0] = dp[i - 1][1];
		for (int k = 1;k < 9;k++) {
			dp[i][k] = dp[i - 1][k - 1] + dp[i - 1][k + 1];
			if (dp[i][k] > 1000000000)
				dp[i][k] %= 1000000000;
		}
		dp[i][9] = dp[i - 1][8];
	}
	for (int k = 1;k <= 9;k++) {
		dp[N][0] += dp[N][k];
		if (dp[N][0] > 1000000000)
			dp[N][0] %= 1000000000;
	}
	cout << dp[N][0];
}