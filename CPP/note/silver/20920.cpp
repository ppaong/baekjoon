#include <iostream>
#include <map>
#include <set>
using namespace std;
//set in map is useful when multiple alignment is required
int main() {
	int N, M;
	cin >> N >> M;
	map<string, int> S;
	map<int, set<string>, greater<int>> L;
	string term;
	int K;
	for (int i = 0;i < N;i++) {
		cin >> term;
		if (term.length() < M)
			continue;
		if (S.find(term) != S.end()) {
			K = S[term]++;
			L[K].erase(term);
			L[K + 1].insert(term);
		}
		else {
			S.insert({ term,1 });
			L[1].insert(term);
		}
	}

	map<int, set<string>>::iterator iter;
	map<int, set<string>, greater<int>> TERM;
	for (iter = L.begin();iter != L.end();iter++) {
		for (string C : iter->second)
			TERM[C.length()].insert(C);
		map<int, set<string>>::iterator ITER;
		for (ITER = TERM.begin();ITER != TERM.end();ITER++)
			for (string C : ITER->second)
				cout << C << "\n";
		TERM.clear();
	}
}