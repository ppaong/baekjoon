#include <iostream>
using namespace std;

int** matrix_mult(int** A,int** B, int n) {
	int** C = new int* [n];
	int c;
	for (int i = 0;i < n;i++) {
		C[i] = new int[n];
		for (int j = 0;j < n;j++) {
			c = 0;
			for (int k = 0;k < n;k++)
				c += A[i][k] * B[k][j];
			if (c >= 1000)
				c %= 1000;
			C[i][j] = c;
		}
	}
	return C;
}

int** matrix_pow(int** A,int n,long long pow) {
	if (pow <= 1)
		return A;

	long long m = pow / 2;
	
	int** A_m = matrix_pow(A, n, m);
	int** A_n = matrix_mult(A_m, A_m, n);
	if (pow % 2 == 1)
		A_n = matrix_mult(A_n, A, n);

	return A_n;
}

void mod(int** A, int n) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (A[i][j] >= 1000) {
				A[i][j] %= 1000;
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	long long pow;
	cin >> n >> pow;

	int** A = new int*[n];

	for (int i = 0;i < n;i++) {
		A[i] = new int[n];
		for (int j = 0;j < n;j++) {
			cin >> A[i][j];
		}
	}

	mod(A, n);
	int** A_n = matrix_pow(A, n, pow);

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n-1;j++) {
			cout << A_n[i][j] << " ";
		}
		cout << A_n[i][n-1] << "\n";
	}
}