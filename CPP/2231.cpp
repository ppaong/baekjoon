#include <iostream>
using namespace std;

int d(int N) {
	int S = N;
	for (int i = 1;i <= N;i *= 10) {
		S += (N / i) % 10;
	}
	return S;
}
int main() {
	int N, K=0;//N<10^K
	cin >> N;
	for (int i = 1;i<=N;i*=10) {
		K++;
	}
	int S = 9 * K;
	int T = N - S;
	for (int i = 0;i < S;i++) {
		if (N == d(T + i)) {
			cout << T + i;
			return 0;
		}
	}
	cout << 0;
	return 0;
}
