#include <iostream>
#include <set>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	set<int> S;
	int term;
	for (int i = 0;i < N;i++) {
		cin >> term;
		S.insert(term);
	}
	int I=0, U=N;
	for (int i = 0;i < M;i++) {
		cin >> term;
		if (S.find(term) != S.end())
			I++;
		else
			U++;
	}
	cout << U - I;
}
