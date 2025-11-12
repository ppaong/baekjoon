#include <iostream>
using namespace std;

char A[1002];
char B[1002];
int dp[1002][1002]{};

int main()
{
	cin >> (A + 1) >> (B + 1);

	int i = 1, j = 1;
	for (i = 1; A[i] != '\0'; i++) {
		for (j = 1; B[j] != '\0';j++) {
			dp[i][j] = (A[i] != B[j] ? max(dp[i - 1][j], dp[i][j - 1]) : dp[i - 1][j - 1] + 1);
		}
	}
	i--;
	j--;
	cout << i + j - dp[i][j];
}
