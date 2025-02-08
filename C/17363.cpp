#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	char** F = new char* [N];
	map<char, char> T = {
		{'.','.'},
		{'O','O'},
		{'-','|'},
		{'|','-'},
		{'/','\\'},
		{'\\','/'},
		{'^','<'},
		{'<','v'},
		{'v','>'},
		{'>','^'}
	};
	for (int i = 0;i < N;i++) {
		F[i] = new char[M];
		for (int j = 0;j < M;j++) {
			cin >> F[i][j];
		}
	}
	for (int j = M-1;j >= 0;j--) {
		for (int i = 0;i < N;i++) {
			cout << T[F[i][j]];
		}
		cout << "\n";
	}
}