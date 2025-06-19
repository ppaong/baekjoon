#include <iostream>
#include <string>
using namespace std;

int main() {
	int N = -1;
	string term;
	for (;!cin.eof();) {
		cin >> term;
		N++;
	}
	cout << N;
}
