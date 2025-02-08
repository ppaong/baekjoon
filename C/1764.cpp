#include <iostream>
#include <unordered_set>
#include <set>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	unordered_set<string> S;
	string term;
	for (int i = 0;i < N;i++) {
		cin >> term;
		S.insert(term);
	}
	set<string> L;
	for (int i = 0;i < M;i++) {
		cin >> term;
		if (S.find(term) != S.end())
			L.insert(term);
	}
	cout << L.size() << "\n";
	for (string C : L)
		cout << C << "\n";
}

