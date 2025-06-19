#include <iostream>
#include <string>
using namespace std;

int main() {
	int N[26];
	for (int& n : N)
		n = -1;
	string term;
	cin >> term;
	int i = 0;
	for (char &C : term) {
		if (N[(int)C - 97] == -1)
			N[(int)C - 97] = i;
		i++;
	}
	for (int& n : N)
		cout << n << " ";
}
