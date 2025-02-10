#include <iostream>
#include <set>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	set<int> S;
	int term;
	for (int i = 0;i < N;i++) {
		cin >> term;
		S.insert(term);
	}
	int M;
	cin >> M;
	for (int i = 0;i < M;i++) {
		cin >> term;
		cout << (S.find(term) != S.end() ? "1\n" : "0\n");
	}
}
