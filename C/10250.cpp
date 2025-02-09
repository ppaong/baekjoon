#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	int W, H, N;
	int X, Y;
	for (int i = 0;i < T;i++) {
		cin >> H >> W >> N;
		X = (N + H - 1) / H;
		Y = N % H == 0 ? H : N % H;
		if (X < 10)
			cout << Y << "0" << X << "\n";
		else
			cout << Y << X << "\n";
	}
}