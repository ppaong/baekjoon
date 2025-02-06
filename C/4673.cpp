#include <iostream>
using namespace std;

const int MAX_N = 10000;

int d(int N) {
	int S = N;
	for (int i = 1;i <= N;i *= 10) {
		S += (N / i) % 10;
	}
	return S;
}
int main() {
	bool A[MAX_N] = {false};
	int count = 0;
	for (int i = 1;i < MAX_N; i++) {
		if (!A[i])
			cout << i << "\n";
		for (int j = i;;) {
			j = d(j);
			if (j >= MAX_N || A[j])
				break;
			A[j]=true;
		}
	}
}