#include <iostream>
using namespace std;

int table[1025][1025];

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	int term;
	for (int k = 0;k <= N;k++) {
		table[0][k] = 0;
		table[k][0] = 0;
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> term;
			table[i][j] = table[i - 1][j] + table[i][j - 1] + term - table[i - 1][j - 1];
		}
	}

	int x1, y1, x2, y2;
	for (int k = 0;k < M;k++) {
		cin >> x1 >> y1 >> x2 >> y2;
		int value = table[x1 - 1][y1 - 1] + table[x2][y2] - table[x2][y1 - 1] - table[x1 - 1][y2];
		cout << value << "\n";
	}
}