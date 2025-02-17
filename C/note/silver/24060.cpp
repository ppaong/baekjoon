#include <iostream>
using namespace std;

int K;

void merge(int* A, int P, int Q, int R) {
	int* tmp = new int[R - P + 1];
	int t = 0;
	int i = P, j = Q + 1;
	for (;i <= Q && j <= R;) {
		if (A[i] <= A[j])
			tmp[t++] = A[i++];
		else
			tmp[t++] = A[j++];
	}
	for (;i <= Q;)
		tmp[t++] = A[i++];
	for (;j <= R;)
		tmp[t++] = A[j++];
	t = 0;
	i = P;
	for (;i <= R;) {
		A[i++] = tmp[t++];
		if (K-- == 1)
			cout << A[i - 1];
	}	
	delete[]tmp;
}
void merge_sort(int* A, int P, int R) {
	if (P < R) {
		int Q = (R + P) / 2;
		merge_sort(A, P, Q);
		merge_sort(A, Q + 1, R);
		merge(A, P, Q, R);
	}
}
int main() {
	int N;
	cin >> N >> K;
	int* A = new int[N];
	for (int i = 0;i < N;i++)
		cin >> A[i];
	merge_sort(A, 0, N - 1);
	if (K >= 1)
		cout << -1;
}