#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int** L;
bool** CHECKED;
int missing = 0;
queue<pair<int, int>> Q;
int current;

void f(int x, int y) {
	int dir[4][2] = { {x + 1,y},{x,y + 1},{x - 1,y},{x,y - 1} };
	for (int e = 0;e < 4;e++) {
		int i = dir[e][0];
		int j = dir[e][1];

		if (!CHECKED[i][j]) {
			CHECKED[i][j] = true;
			if (L[i][j] >= 0)
				Q.push(make_pair(i, j));
		}
	}
	
}

int diffusion() {
	int time = 0;
	pair<int, int> term;
	current = Q.size();

	for (;;time++) {
		if (current <= 0)
			break;

		for (int e = 0;e < current;e++) {
			term = Q.front();
			f(term.first, term.second);
			//L[term.first][term.second] = time;//debug
			missing--;
			Q.pop();
		}

		current = Q.size();
	}

	return (time - 1);
}

int main(){
	cin >> m >> n;
	L = new int* [n+2];
	CHECKED = new bool* [n + 2];
	for (int i = 1;i <= n;i++) {
		L[i] = new int[m + 2];
		CHECKED[i] = new bool[m + 2] {false, };

		for (int j = 1;j <= m;j++) {
			cin >> L[i][j];
			if (L[i][j] >= 0) {
				missing++;

				if (L[i][j] >= 1) {
					Q.push(make_pair(i, j));
					CHECKED[i][j] = true;
				}
			}
		}

		CHECKED[i][0] = true;
		CHECKED[i][m + 1] = true;
	}
	CHECKED[0] = new bool[m + 2];
	CHECKED[n + 1] = new bool[m + 2];
	for (int i = 0;i <= m + 1;i++) {
		CHECKED[0][i] = true;
		CHECKED[n + 1][i] = true;
	}



	int t = diffusion();
	cout << (missing > 0 ? -1 : t);
}

/*
void debug_CHECK() {
	cout << "\n";
	for (int i = 0;i <= n + 1;i++) {
		for (int j = 0;j <= m + 1;j++) {
			cout << CHECKED[i][j];
		}
		cout << "\n";
	}
}
void debug_L() {
	cout << "\n";
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			std::printf("%2d ", L[i][j]);
		}
		cout << "\n";
	}
}
*/