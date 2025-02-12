#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> S;
	int term;
	for (int i = 0;i < N;i++) {
		cin >> term;
		S.push_back(term);
	}
	sort(S.begin(), S.end());
	cout << S.front() * S.back();
}