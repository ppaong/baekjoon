#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> S;
	vector<int>::iterator iter;
	int term;
	for (int i = 0;i < N;i++) {
		cin >> term;
		S.push_back(term);
	}
	sort(S.begin(), S.end());

	int count = N / 2, succession = 1, num = 10000;
	int mean = 0, median = 0, mode_max = 1, max = -4000, min = 4000;
	vector<int> mode;
	for (int& K : S) {
		mean += K;

		if (count-- == 0)
			median = K;

		succession++;
		if (K!= num) {
			num = K;
			succession = 1;
		}
		if (succession == mode_max) {
			mode.push_back(num);
		}
		else if (succession > mode_max) {
			mode_max = succession;
			if (mode.front() != num) {
				mode.clear();
				mode.push_back(num);
			}
		}

		if (K > max)
			max = K;
		if (K < min)
			min = K;
	}

	mean = (int)round(mean / (double)N);
	cout << mean << "\n" << median << "\n" << (mode.size() >= 2 ? mode[1] : mode[0]) << "\n" << max - min;
}