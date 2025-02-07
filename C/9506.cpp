#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int N;
	vector<int> factor;
	int sum;
	for (;;) {
		cin >> N;
		if (N < 0)
			break;

		factor.clear();
		sum = 0;
		for (int i = 2;i * i <= N;i++) {
			if (N % i == 0) {
				factor.push_back(i);
				factor.push_back(N / i);
				sum += i + N / i;
			}
		}

		cout << N;
		if (sum + 1 == N) {
			cout << " = 1";
			sort(factor.begin(), factor.end());
			for (int k : factor)
				cout << " + " << k;
		}
		else
			cout << " is NOT perfect.";
		cout << "\n";
	}
}