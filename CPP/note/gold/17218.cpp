#include <iostream>
using namespace std;

char A[42];
char B[42];
int dp[42][42]{};

int main()
{
	cin >> (A + 1) >> (B + 1);

	int i = 1, j = 1;
	int m = 0;
	for (i = 1; A[i] != '\0'; i++) {
		for (j = 1; B[j] != '\0';j++) {
			dp[i][j] = (A[i] != B[j] ? max(dp[i - 1][j], dp[i][j - 1]) : dp[i - 1][j - 1] + 1);
		}
	}
	i--;
	j--;

	int len = dp[i][j];
	char* str = new char[len + 1];
	str[len--] = '\0';

	for (; i > 0 && j > 0;) {
		if (A[i] == B[j]) {
			str[len--] = A[i];
			if (len < 0)
				break;
			i--;
			j--;
		}
		else {
			if (dp[i - 1][j] > dp[i][j - 1])
				i--;
			else
				j--;
		}
	}
	cout << str;
}
