#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> a = { 0,1 };
	for (int i = 0;i < N-1;i++) {
		a.push_back(a[i] + a[i + 1]);
	}
	cout << a[N] << " " << a.size() - 3;
	return 0;
}