#include <iostream>
using namespace std;

int main() {

	long long* P = new long long[100];
	P[0] = 1;
	P[1] = 1;
	P[2] = 1;
	P[3] = 2;
	P[4] = 2;
	for (int i = 5;i < 100;i++)
		P[i] = P[i - 1] + P[i - 5];
	
	int T;
	cin >> T;
	int N;
	for (int i = 0;i<T;i++) {
		cin >> N;
		cout << P[N - 1] << "\n";
	}
}