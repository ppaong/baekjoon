#include <iostream>
using namespace std;
//find P2, using P1 and rotation matrix. 
//then direction(CCW,CW) can be found by outer product
int main() {
	int X[3], Y[3];
	cin >> X[0] >> Y[0] >> X[1] >> Y[1] >> X[2] >> Y[2];
	X[0] -= X[1];
	Y[0] -= Y[1];
	X[2] -= X[1];
	Y[2] -= Y[1];
	int outer_product = X[0] * Y[2] - X[2] * Y[0];
	cout << (outer_product != 0 ? outer_product > 0 ? -1 : 1 : 0);
}