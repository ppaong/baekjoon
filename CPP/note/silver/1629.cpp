#include <iostream>
using namespace std;

long long power_mod(long long a, long long  b, long long c) {//a^b mod c
	if (b <= 1)
		return a % c;
	long long p = power_mod(a, b / 2, c);
	if (b % 2 == 0)
		return (p * p) % c;
	return (p * power_mod(a, b / 2 + 1, c)) % c;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int A, B, C;
	cin >> A >> B >> C;
	cout << power_mod(A, B, C);
}
