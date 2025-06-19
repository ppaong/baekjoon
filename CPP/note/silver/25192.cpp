#include <iostream>
#include <set>
#include <string>
using namespace std;
//hash-collision could happen in unordered_set
int main() {
	int N;
	cin >> N;
	set<string> S;
	string term;
	int count = 0;
	for (int i = 0;i < N;i++) {
		cin >> term;
		if (term == "ENTER")
			S.clear();
		else if (S.find(term) == S.end()) {
			count++;
			S.insert(term);
		}
	}
	cout << count;
}
