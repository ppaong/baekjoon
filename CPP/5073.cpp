#include <iostream>
using namespace std;

int main() {
	int A, B, C ,S;
	for (;;) {
		S = 0;
		cin >> A >> B >> C;

		if (A == 0)
			break;

		if (A >= B) {
			S -= B;
			if (C >= A)
				S += C - A;
			else
				S += A - C;
		}
		else {
			S -= A;
			if (C >= B)
				S += C - B;
			else
				S += B - C;
		}

		if (S >= 0)
			cout << "Invalid" << endl;
		else if (A == B) {
			if (B == C) {
				cout << "Equilateral" << endl;
			}
			else
				cout << "Isosceles" << endl;
		}
		else if (B == C || A == C)
			cout << "Isosceles" << endl;
		else
			cout << "Scalene" << endl;
	}
}