#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	set<string> S;
	string term;
	for (int i = 0;i < N;i++) {
		cin >> term;
		S.insert(term);
	}

	int count = 0;
	for (int i = 0;i < M;i++) {
		cin >> term;
		if (S.find(term) != S.end()) {
			count++;
		}
	}
	cout << count;
}
