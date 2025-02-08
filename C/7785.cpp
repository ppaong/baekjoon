#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	map<string,bool, greater<string>> S;
	map<string, bool> V = { {"enter",true} ,{"leave",false} };
	string name, value;
	for (int i = 0;i < N;i++) {
		cin >> name >> value;
		S[name] = V[value];
	}
	for (map<string, bool>::iterator iter = S.begin();iter != S.end();iter++) {
		if (iter->second)
			cout << iter->first << "\n";
	}
}
