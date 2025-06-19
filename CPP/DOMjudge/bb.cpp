#include <iostream>
using namespace std;

void fillDown(int** room, int x, int y, int len, int value) {
	for (int i = 1;i < len;i++)
		room[x][y + i] = room[x][y + i - 1] + value;
}
void fillRight(int** room, int x, int y, int len, int value) {
	for (int i = 1;i < len;i++)
		room[x + i][y] = room[x + i - 1][y] + value;
}
int main() {
	int N, target;
	cin >> N >> target;
	int** room = new int* [N];
	for (int i = 0;i < N;i++)
		room[i] = new int[N];

	for (int i = 0;i < N / 2;i++) {
		room[i][i] = (N - 2 * i) * (N - 2 * i);
		fillDown(room, i, i, (N - 2 * i), -1);
		fillRight(room, i, N - i - 1, (N - 2 * i), -1);

		room[i + 1][i] = (N - 2 * i - 2) * (N - 2 * i - 2) + 1;
		fillRight(room, i + 1, i, (N - 2 * i) - 1, 1);
		fillDown(room, N - i - 1, i, (N - 2 * i), 1);
	}
	room[N / 2][N / 2] = 1;

	int x=1, y=1;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cout << room[j][i] << " ";
			if (room[j][i] == target) {
				x += i;
				y += j;
			}
		}
		cout << "\n";
	}
	cout << x << " " << y;
}
