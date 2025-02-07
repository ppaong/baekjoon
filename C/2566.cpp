#include <iostream>
using namespace std;

void matrixInput(int N,int M, int** &A) {
	A = new int* [N];
	for (int i = 0;i < N;i++) {
		A[i] = new int[M];
		for (int j = 0;j < M;j++) {
			cin >> A[i][j];
		}
	}
}
int main(){
	int** A;
	matrixInput(9, 9, A);
	int max = -1, P = 0, Q = 0;
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			if (A[i][j] > max) {
				max = A[i][j];
				P = i + 1;
				Q = j + 1;
			}
		}
	}
	cout << max << "\n" << P << " " << Q;
}