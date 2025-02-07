#include <iostream>
using namespace std;

void matrixInput(int &N,int &M, int** &A) {
	A = new int* [N];
	for (int i = 0;i < N;i++) {
		A[i] = new int[M];
		for (int j = 0;j < M;j++) {
			cin >> A[i][j];
		}
	}
}

int main(){
	int N, M;
	cin >> N >> M;
	int** A;
	int** B;
	matrixInput(N, M, A);
	matrixInput(N, M, B);
	for (int i = 0;i < N;i++) {
		cout << A[i][0] + B[i][0];
		for (int j = 1;j < M;j++) {
			cout << " " << A[i][j] + B[i][j];
		}
		cout << "\n";
	}
}