#include <iostream>
using namespace std;
//0
//1
//11 2
//111 21 12 = [11 21]1 [1]2
//1111 211 121 112 22 = [111 21 12]1 [11 2]2
//...

int main() {
	int N;
	cin >> N;
	int* A = new int[N + 1];
	A[0] = 1;//0 C 0 = 1
	A[1] = 1;//1 C 0 = 1
	for (int i = 2;i <= N;i++) {
		A[i] = A[i - 1] + A[i - 2];
		if (A[i] >= 10007)//mod
			A[i] %= 10007;
	}
	cout << A[N];
}

//1904 is same problem
//11726 is similar problem