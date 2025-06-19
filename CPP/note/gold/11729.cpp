#include <iostream>
using namespace std;

void f(int& a, int& b, int& c, int n) {
	if (n <= 1) {
		cout << a << " " << c << "\n";
	}
	else {
		f(a, c, b, n - 1);
		cout << a << " " << c << "\n";
		f(b, a, c, n - 1);
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	unsigned int K = 1;
	for (int i = 0;i < N;i++) K *= 2;
	cout << K - 1 << "\n";
	int a = 1, b = 2, c = 3;
	f(a, b, c, N);
}