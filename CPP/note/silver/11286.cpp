#include <iostream>
#include <map>
using namespace std;

int main() {
	int N;
	cin >> N;
	map<int, int[2]> S;//[0] - [1] +
	int term;
	for (int i = 0;i < N;i++) {
		cin >> term;
		if (term != 0) {
			S[abs(term)][term > 0 ? 1 : 0]++;
		}
		else {
			if (!S.empty()) {
				if (S.begin()->second[0] != 0) {
					S.begin()->second[0]--;
					cout << -S.begin()->first << "\n";
				}
				else if (S.begin()->second[1] != 0) {
					S.begin()->second[1]--;
					cout << S.begin()->first << "\n";
				}
				if (S.begin()->second[0] == 0 && S.begin()->second[1] == 0)
					S.erase(S.begin());
			}
			else
				cout << "0\n";
		}
	}
}