#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	set<string> S;
	string term;
	cin >> term;
	int L = term.length();
	for (int i = 0;i < L;i++)
		for (int j = 0;j < L - i;j++)
			S.insert(term.substr(i, j + 1));
	cout << S.size();
}