#include <iostream>
using namespace std;

int n, m;
int** L;
bool** visited;

void f(int x, int y) {
	L[x][y] = 0;
	visited[x][y] = true;

	int* A[2] = { new int[n + m], new int[n + m] };
	int A_index = 0;
	int* B[2] = { new int[n + m], new int[n + m] };
	int B_index = 0;

	A[0][0] = x;
	A[1][0] = y;
	A_index++;

	for (int e = 1;;e++) {
		if (A_index <= 0)
			break;

		for (int k = 0;k < A_index;k++) {
			int i = A[0][k];
			int j = A[1][k];

			int dir[2][4] = { {i + 1,i,i - 1,i} ,{j,j + 1,j,j - 1} };

			for (int z = 0;z < 4;z++) {
				int i = dir[0][z];
				int j = dir[1][z];

				if (!visited[i][j]) {
					visited[i][j] = true;

					if (L[i][j] > 0) {
						L[i][j] = e;
						B[0][B_index] = i;
						B[1][B_index] = j;
						B_index++;
					}
				}
			}
		}
		swap(A, B);
		A_index = B_index;
		B_index = 0;
	}
	return;
}

int main() {
	cin >> n >> m;

	L = new int* [n + 2];
	visited = new bool* [n + 2];

	int s_x = 0, s_y = 0;
	for (int i = 1;i <= n;i++) {
		L[i] = new int[m + 2];
		visited[i] = new bool[m + 2] {false, };
		for (int j = 1;j <= m;j++) {
			cin >> L[i][j];
			if (L[i][j] == 2) {
				s_x = i;
				s_y = j;
			}
		}
		L[i][0] = 0;
		L[i][m + 1] = 0;
	}
	L[0] = new int[m + 2] {0,};
	L[n+1] = new int[m + 2] {0, };
	visited[0] = new bool[m + 2] {false, };
	visited[n+1] = new bool[m + 2] {false, };

	f(s_x, s_y);

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j < m;j++) {
			cout << (visited[i][j] ? L[i][j] : -1) * (L[i][j] != 0) << " ";
		}
		cout << (visited[i][m] ? L[i][m] : -1) * (L[i][m] != 0) << "\n";
	}
}
 