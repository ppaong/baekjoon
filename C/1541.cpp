#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;
	string::iterator P = S.begin();
	int sum = 0;
	bool isPlus = true;
	for (string::iterator iter = P;iter != S.end();iter++) {
		if (*iter == '+' || *iter == '-') {
			sum += isPlus ? stoi(string(P, iter)) : -stoi(string(P, iter));
			if (*iter == '-')
				isPlus = false;
			iter++;
			P = iter;
		}
	}
	sum += isPlus ? stoi(string(P, S.end())) : -stoi(string(P, S.end()));
	cout << sum;
}