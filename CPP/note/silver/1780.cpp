#include <iostream>
using namespace std;

int field[2200][2200];
int sum[4]{ 0, };

int f(int x, int y, int n) {
	if (n <= 1)
		return field[x][y];
	
	n /= 3;
	int t[3][3];
	bool trigger = false;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			t[i][j] = f(x + i * n, y + j * n, n);
			if (field[x][y] != t[i][j])
				trigger = true;
		}
	}
	if (trigger) {
		for (int i = 0;i < 3;i++)
			for (int j = 0;j < 3;j++)
				sum[t[i][j]]++;
		return 3;
	}
	else
		return field[x][y];
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> field[j][i];
			field[j][i]++;// -1->0 , 0->1 , 1->2;
		}
	}
	int a = f(0, 0, N);
	sum[a]++;
	cout << sum[0] << "\n" << sum[1] << "\n" << sum[2];
}
