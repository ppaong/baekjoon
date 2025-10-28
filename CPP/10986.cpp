#include <iostream>
using namespace std;

int a[1001]{ 0, };

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	int term;
	int partial_sum = 0;

	for (int i = 0;i < N;i++) {
		cin >> term;
		partial_sum = (partial_sum + term % M) % M;
		a[partial_sum]++;
	}

	long long pair_sum = a[0] > 1 ? ((long long)a[0] * (a[0] + 1)) / 2 : a[0];
	for (int i = 1;i < M;i++) {
		if (a[i] > 1)
			pair_sum += ((long long)a[i] * (a[i] - 1)) / 2;
	}

	cout << pair_sum;
}