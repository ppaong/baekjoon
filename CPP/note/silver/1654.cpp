#include <iostream>
#include <algorithm>
using namespace std;

unsigned int parametric_search(unsigned int* _First, unsigned int* _Last, const unsigned int& Val) {
	int L = 0, R = _Last - _First - 1, M = (L + R) >> 1;
	for (;L <= R;M = (L + R) >> 1) {
		if (_First[M] >= Val)// >= not contain Val , > contain Val
			R = M - 1;
		else
			L = M + 1;
	}
	return R;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	unsigned int N, M;
	cin >> N >> M;
	unsigned int* S = new unsigned int[N];
	for (int i = 0;i < N;i++)
		cin >> S[i];
	sort(S, S + N);

	unsigned int sum = 0;
	unsigned int L = 1, R = S[N - 1] / (M / N), K = (L + R) >> 1;
	for (;L <= R;K = (L + R) >> 1) {
		sum = 0;
		for (unsigned int i = K;i <= S[N - 1];i += K)
			sum += N - parametric_search(S, S + N, i) - 1;
		if (sum < M)
			R = K - 1;
		else
			L = K + 1;
	}
	cout << R;
}