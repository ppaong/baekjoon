#include <iostream>
using namespace std;

char A[101];
char B[101];
char C[101];
int dp[101][101][101]{};

int main()
{
	cin >> A >> B >> C;
	for (int i = 0; i < 101; i++) {
		dp[i][0][0] = 0;
		dp[0][i][0] = 0;
		dp[0][0][i] = 0;
	}

	int i = 0, j = 0, k = 0;
	for (i = 0; A[i] != '\0'; i++) {
		for (j = 0; B[j] != '\0'; j++) {
			for (k = 0; C[k] != '\0'; k++) {
				dp[i + 1][j + 1][k + 1] = ((A[i] == B[j] && B[j] == C[k]) ? dp[i][j][k] + 1 : max(max(dp[i + 1][j + 1][k], dp[i + 1][j][k + 1]), dp[i][j + 1][k + 1]));
			}
		}
	}

	cout << dp[i][j][k];
}
