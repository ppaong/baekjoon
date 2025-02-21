#include <iostream>
using namespace std;
//pisano period
int main() {
	long long N;
	cin >> N;
	int* F = new int[1500000];
	F[0] = 0;
	F[1] = 1;
	for (int  i = 2;i <= 1500000;i++) {
		F[i] = F[i - 1] + F[i - 2];
		if (F[i] > 1000000)
			F[i] %= 1000000;
	}
	cout << F[N%1500000];
}