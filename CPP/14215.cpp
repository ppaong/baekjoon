#include <iostream>
using namespace std;

int main() {
	int A, B, C, S = 0;
	cin >> A >> B >> C;

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
		cout << A + B + C - S - 1 << endl;
	else
		cout << A + B + C << endl;
}