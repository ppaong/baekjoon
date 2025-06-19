#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	set<int> S;

	cin >> N;
	int term;
	for (int i = 0;i < N;i++) {
		cin >> term;
		S.insert(term);
	}	

	cin >> M;
	cin >> term;
	set<int>::iterator iter = S.find(term);
	cout << (iter != S.end() ? 1 : 0);
	for (int i = 1;i < M;i++) {
		cin >> term;
		iter = S.find(term);
		cout << " " << (iter != S.end() ? 1 : 0);
	}
}
