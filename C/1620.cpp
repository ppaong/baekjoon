#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;//1<=N,M<=100000
	cin >> N >> M;

	unordered_map<string, string> D;
	string term,num;
	for (int i = 1;i <= N;i++) {
		cin >> term;
		num = to_string(i);
		D.insert({ term, num });
		D.insert({ num, term });
	}
	for (int i = 0;i < M;i++) {
		cin >> term;
		cout << D[term] << "\n";
	}
}