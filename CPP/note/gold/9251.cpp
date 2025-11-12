#include <iostream>
using namespace std;

char A[1001];
char B[1001];
int dp[1001][1001];

int main()
{
	cin >> A >> B;
	for (int i = 0; i < 1001; i++) {
		dp[i][0] = 0;
		dp[0][i] = 0;
	}
	int i = 0, j = 0;
	for (i = 0; A[i] != '\0'; i++) {
		for (j = 0; B[j] != '\0'; j++) {
			dp[i + 1][j + 1] = (A[i] != B[j] ? max(dp[i][j + 1], dp[i + 1][j]) : dp[i][j] + 1);
		}
	}
	cout << dp[i][j];
}
