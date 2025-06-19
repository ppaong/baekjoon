#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


bool myCompare(const pair<int, string>& a, const pair<int, string>& b) {
	if (a.first == b.first) {
		if (a.second.length() == b.second.length()) {
			return a.second > b.second;
		}
		return a.second.length() > b.second.length();
	}
	return a.first > b.first;
}
int main() {
	int N, M;
	string term;
	map<string, int> S;
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		cin >> term;
		if (term.length() >= M)
			S[term] += 1;
	}
	int len = S.size();
	int i = 0;
	pair<int, string>* voca = new pair<int, string>[len];
	
	for (map<string, int>::iterator iter=S.begin();iter != S.end();iter++)
		voca[i++] = pair<int, string>(iter->second, iter->first);

	sort(voca, voca + len, myCompare);

	for (int i = 0;i < len;i++)
		cout << voca[i].second << "\n";
}