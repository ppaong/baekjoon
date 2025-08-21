#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int** L;
bool** VISITED;
queue<pair<int, int>> Q;
int currenct = 0;

bool check(int x, int y, int d) {
	if (L[x][y]==0)
		return false;

	L[x][y] = d;

	if (x == n && y == m)
		return true;

	int dir[2][4] = { {x + 1,x,x - 1,x},{y,y + 1,y,y - 1} };

	for (int e = 0;e < 4;e++) {
		int i = dir[0][e];
		int j = dir[1][e];

		if (!VISITED[i][j]) {
			VISITED[i][j] = true;
			Q.push(make_pair(i, j));
		}
	}

	return false;
}

int main() {
	cin >> n >> m;
	L = new int* [n + 2];
	VISITED = new bool* [n + 2];


	char* str = new char[m];
	for (int i = 1;i <= n;i++) {
		L[i] = new int[m + 2];
		VISITED[i] = new bool[m + 2] {false, };
		cin >> str;
		for (int j = 1;j <= m;j++) {
			L[i][j] = (str[j - 1] == '1');
		}
		L[i][0] = false;
		L[i][m + 1] = false;
	}
	L[0] = new int[m + 2] {0, };
	L[n + 1] = new int[m + 2] {0, };
	VISITED[0] = new bool[m + 2] {false, };
	VISITED[n + 1] = new bool[m + 2] {false, };



	currenct = 1;
	VISITED[1][1] = true;
	Q.push(make_pair(1, 1));

	pair<int, int> term;
	for (int c = 1;;c++) {
		for (int e = 0;e < currenct;e++) {
			term = Q.front();
			if (check(term.first, term.second, c)) {
				cout << c;
				return 0;//end code
			}
			Q.pop();
		}
		currenct = Q.size();
	}
}


/*
void debug() {
	cout << "\n";
	for (int i = 0;i <= n + 1;i++) {
		for (int j = 0;j <= m + 1;j++) {
			std::printf("%3d ", L[i][j]);
		}
		cout << "\n";
	}
}
*/
