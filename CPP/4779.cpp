#include <iostream>
using namespace std;

int main() {
	for (;;) {
		int N;
		cin >> N;
		if (cin.eof())
			break;

		int L = 1;
		for (int i = 0;i < N;i++)
			L *= 3;

		char* C = new char[L];
		for (int i = 0;i < L;i++)
			C[i] = '-';

		int P = 1, Q = L / 3;
		for (;;) {
			for (int i = 0;i < P;i++)
				for (int j = 0;j < Q;j++)
					C[(3 * i + 1) * Q + j] = ' ';
			if (Q <= 1)
				break;
			P *= 3;
			Q /= 3;
		}
		for (int i = 0;i < L;i++)
			cout << C[i];
		cout << "\n";

		delete[]C;
	}
}