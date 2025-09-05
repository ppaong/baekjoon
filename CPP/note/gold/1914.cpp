#include <iostream>
using namespace std;

int f(int A, int B, int C, int n) {
	if (n <= 1) {
		cout << A << " " << C << "\n";
		return 1;
	}
		
	int k=0;
	k += f(A, C, B, n - 1);
	cout << A << " " << C << "\n";
	k++;
	k += f(B, A, C, n - 1);
	
	return k;
}

class integer {
private:
	char* L;
	unsigned int max;
	unsigned int digit;
public:
	integer(int number=0,unsigned int max=100) :max(max), L(new char[max] {0, }) {
		for (digit = 0;;digit++) {
			L[digit] = number % 10;
			if (number < 10)
				break;
			number /= 10;
		}
		digit++;
	}

	void mult(const int& ref) {
		if (ref > 2)
			return;

		L[0] *= ref;
		for (int i = 1;i < digit;i++) {
			L[i] *= ref;
			if (L[i-1] >= 10) {
				L[i-1] -= 10;
				L[i] += 1;
			}
		}

		if (L[digit - 1] >= 10) {
			L[digit - 1] -= 10;
			L[digit] += 1;
		}

		if (L[digit] > 0)
			digit++;
	}

	void sub(const int& ref) {
		if (ref > 10)
			return;

		L[0] -= ref;
		for (int i = 0;i < digit;i++) {
			if (L[i] < 0) {
				L[i] += 10;
				L[i + 1] -= 1;
			}
			else
				return;
		}
	}

	void print() {
		for (int i = digit-1;i >= 0;i--) {
			cout << (int)L[i];
		}
	}
};

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	integer k(1);
	
	for (int i = 0;i < n;i++) {
		k.mult(2);
	}
	k.sub(1);
	k.print();
	cout << "\n";

	if (n <= 20) {
		f(1, 2, 3, n);
	}
}