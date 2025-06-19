#include <iostream>
using namespace std;

void AttachPaper(int A, int B,bool** &M) {
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			M[A + i][B + j] = true;
		}
	}
}

int main(){
	int X = 100, Y = 100;
	bool** D = new bool* [X];
	for (int i = 0;i < X;i++)
		D[i] = new bool[Y] {false};
	int N;
	cin >> N;
	int A, B;
	for (int i = 0;i < N;i++) {
		cin >> A >> B;
		AttachPaper(A, B, D);
	}
	int area = 0;
	for (int i = 0;i < X;i++)
		for (int j = 0;j < Y;j++)
			if (D[i][j])
				area++;
	cout << area;
}
