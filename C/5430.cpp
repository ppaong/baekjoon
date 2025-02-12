#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	string P;
	int N;
	string term;
	string::iterator iter;
	string::iterator pos;
	deque<int> S;
	for (int k = 0;k < T;k++) {
		cin >> P >> N >> term;
		term.pop_back();
		term.push_back(',');
		pos = term.begin() + 1;
		iter = pos + 1;
		for (int i = 0;i < N;) {
			if (*iter == ',') {
				i++;
				S.push_back(stoi(string(pos, iter)));
				pos = iter + 1;
			}
			iter++;
		}

		bool error = false;
		bool isFront = true;
		for (char &command : P) {
			if (command == 'D') {
				if (S.empty()) {
					error = true;
					break;
				}

				if (isFront)
					S.pop_front();
				else
					S.pop_back();
			}
			else
				isFront = !isFront;
		}
		if (!error) {
			cout << "[";
			if (!S.empty()) {
				if (!isFront)
					reverse(S.begin(), S.end());
				cout << S.front();
				S.pop_front();
				for (int& A : S) {
					cout << "," << A;
				}
			}
			cout << "]\n";
		}
		else
			cout << "error\n";

		S.clear();
	}
}