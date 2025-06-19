#include <iostream>
using namespace std;

//0=0       0=0
//1=1       1=1
//4=100     2=10
//5=101     3=11
//16=10000  4=100
//17=10001  5=101
//20=10100  6=110
//21=10101  7=111
//... row+col=number

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	unsigned int N, R, C;
	cin >> N >> R >> C;
	unsigned int L = (1 << 15);
	unsigned int A = 0, B = 0;
	for (int i = 0;i < 16;i++) {
		A |= (L & C);
		B |= (L & R);
		A <<= 1;
		B <<= 1;
		L >>= 1;
	}
	cout << (A >> 1) + B;
}



//short ver

/*
#include <iostream>
using namespace std;
int main() {
	unsigned int N, R, C, L = (1 << 15), A = 0, B = 0;
	cin >> N >> R >> C;
	for (;L;L >>= 1) {
		A |= (L & C);
		B |= (L & R);
		A <<= 1;
		B <<= 1;
	}
	cout << (A >> 1) + B;
}
*/