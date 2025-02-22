#include <iostream>
using namespace std;
//이분탐색
//12738 동일함함
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int* A = new int[N];
	for (int i = 0;i < N;i++)
		cin >> A[i];

	int* S = new int[N + 1] {0};
	int P = 0;
	for (int i = 0;i < N;i++) {
		if (S[P] < A[i]) {
			P++;
			S[P] = A[i];
		}
		else {
			int L = 0, R = P;
			for (;L < R;) {
				int M = (L + R) / 2;
				if (S[M] < A[i])
					L = M + 1;
				else
					R = M;
			}
			S[R] = A[i];
		}
        //for (int i = 0;i <= P;i++)
		//cout << S[i] << " ";
        //cout << "\n";
	}
	cout << P;
}