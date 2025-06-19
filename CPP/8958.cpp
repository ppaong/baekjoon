#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	string term;
	int sum,S;
	for (int i = 0;i < N;i++) {
		sum = 0;
		S = 1;
		cin >> term;
		for (char& C : term) {
			if (C == 'O')
				sum += S++;
			else
				S = 1;
		}
		cout << sum << "\n";
	}
}