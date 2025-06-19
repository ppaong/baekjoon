#include <iostream>
using namespace std;

int main(){
	int N;//N>=3
	cin >> N;
	int V=0;
	if (N >= 10) {
		switch (N % 5) {
		case 0:
			V = N / 5;
			break;
		case 1://V = N / 5 - 1 + 2
		case 3://V = N / 5 + 1
			V = N / 5 +1;
			break;
		case 2://V = N / 5 - 2 + 4;
		case 4://V = N / 5 - 1 + 3;
			V = N / 5 + 2;
			break;
		}
	}
	else {
		switch (N) {
		case 4:
		case 7:
			V = -1;
			break;
		case 3:
		case 5:
			V = 1;
			break;
		case 6:
		case 8:
			V = 2;
			break;
		case 9:
			V = 3;
			break;
		}
	}
	cout << V;
}