#include <iostream>
using namespace std;

char** S;

void box(int N,int X,int Y) {
	if (N <= 1) {
		S[X][Y] = '*';
		return;
	}
	else
	{
		N /= 3;
		box(N, X+0, Y+0);
		box(N, X + N, Y + 0);
		box(N, X + N + N, Y + 0);
		box(N, X + 0, Y + N);
		box(N, X + N + N, Y + N);
		box(N, X + 0, Y + N + N);
		box(N, X + N, Y + N + N);
		box(N, X + N + N, Y + N + N);
	}
		
}

int main() {
	int N;
	cin >> N;
	S = new char* [N];
	for (int i = 0;i < N;i++) {
		S[i] = new char[N];
		for (int j = 0;j < N;j++)
			S[i][j] = ' ';
	}
	box(N, 0, 0);
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cout << S[i][j];
		}
		cout << "\n";
	}
}