#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;

	int** L = new int* [n];
	for (int i = 0;i < n;i++) {
		L[i] = new int[2];
		cin >> L[i][0] >> L[i][1];
	}

	sort(L, L + n,
		[](int* const& A, int* const& B) {
			if (A[1] != B[1])
				return A[1] < B[1];
			else
				return A[0] < B[0];
		});

	int bound = L[0][1];
	int count = 1;
	for (int i = 1;i < n;i++) {
		if (L[i][0] >= bound) {
			bound = L[i][1];
			count++;
		}
	}
	cout << count;
}