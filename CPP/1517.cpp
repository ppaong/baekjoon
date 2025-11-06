#include <iostream>
using namespace std;

int A[500001];
int B[500001];

long long int f(int start, int end) {
	if (end - start <= 0)
		return 0;

	int m = (end + start) / 2;

	long long int l = f(start, m);
	long long int r = f(m + 1, end);
	long long int count = 0;

	int i = start;
	int j = m + 1;
	int k = start;
	
	for (;i<=m && j<=end;) {
		if (A[i] <= A[j]) {
			B[k++] = A[i++];
		}
		else {
			count += (j - k);
			B[k++] = A[j++];
		}
	}
	for(;i <= m;)
		B[k++] = A[i++];
	for (;j <= end;)
		B[k++] = A[j++];

	for (int k = start;k <= end;k++)
		A[k] = B[k];

	return l + r + count;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0;i < N;i++)
		cin >> A[i];

	cout << f(0, N - 1) << "\n";
}