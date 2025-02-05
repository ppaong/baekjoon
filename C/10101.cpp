#include <iostream>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	if (A + B + C != 180)
		cout << "Error" << endl;
	else if (A == B){
		if (B == C)
			cout << "Equilateral" << endl;
		else
			cout << "Isosceles" << endl;
	}
	else if (B == C || A == C)
		cout << "Isosceles" << endl;
	else
		cout << "Scalene" << endl;
	return 0;
}