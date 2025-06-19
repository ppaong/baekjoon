#include <iostream>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	int K = A * B * C;
	int N[10] = { 0 };
	for (int i = 0;K > 0;i++) {
		N[K % 10]++;
		K /= 10;
	}
	for (int i = 0;i < 10;i++)
		cout << N[i] << "\n";
}
