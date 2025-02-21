#include <iostream>
using namespace std;

//연속합이기 때문에 0부터 N-1까지 구간내 최대합만 선택해서 더해나가면 됨

int main() {
	int N;
	cin >> N;
	int* A = new int[N];
	for (int i = 0;i < N;i++)
		cin >> A[i];
	int* DP = new int[N];
	int M = A[0];
	DP[0] = A[0];
	for (int i = 1;i < N;i++) {
		DP[i] = max(A[i] + DP[i - 1], A[i]);
		if (DP[i] > M)
			M = DP[i];
	}
	cout << M;
}
