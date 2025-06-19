#include <iostream>
#include <string>
using namespace std;
//bool array can be used instead of set
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	bool S[21] = { false };

	string term;
	int K;
	for (int k = 0;k < N;k++) {
		cin >> term;
		if (term == "all") {
			for (int i = 1;i <= 20;i++)
				S[i] = true;
		}
		else if (term == "empty") {
			for (int i = 1;i <= 20;i++)
				S[i] = false;
		}
		else {
			cin >> K;
			if (term == "add")
				S[K] = true;
			else if (term == "remove")
				S[K] = false;
			else if (term == "check")
				cout << S[K] << "\n";
			else if (term == "toggle") {
				S[K] = !S[K];
			}
		}
	}
}