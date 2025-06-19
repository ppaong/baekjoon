#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int** F = new int* [N];
	int P = 1;
	F[0] = new int[P + 1] {0};
	F[0][0] = 0;
	F[1] = new int[P + 1] {0};
	F[1][0] = 1;
	for (int  i = 2;i <= N;i++) {
		F[i] = new int[P + 1] {0};
		for (int k = 0;k < P;k++) {
			F[i][k] = F[i - 1][k] + F[i - 2][k];
			if (F[i][k] > 1000000000) {
				F[i][k] -= 1000000000;
				F[i-2][k + 1] += 1;
				if (k == P - 1) 
					P++;
			}
		}
	}
	cout << F[N][P - 1];
	for (int i = P - 2;i >= 0;i--) {
		cout.width(9);
		cout.fill('0');
		cout << F[N][i];
	}
}