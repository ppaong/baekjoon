#include <iostream>
using namespace std;

char A[4001];
char B[4001];
int dp[4001][4001];

int main()
{
	cin >> A >> B;
	for (int i = 0; i < 4001; i++) {
		dp[i][0] = 0;
		dp[0][i] = 0;
	}
	int i = 0, j = 0;
	int max = 0;
	for (i = 0; A[i] != '\0'; i++) {
		for (j = 0; B[j] != '\0'; j++) {
			dp[i + 1][j + 1] = (A[i] != B[j] ? 0 : dp[i][j] + 1);
			if (dp[i + 1][j + 1] > max)
				max = dp[i + 1][j + 1];
		}
	}
	cout << max;
}
