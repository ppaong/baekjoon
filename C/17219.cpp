#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	unordered_map<string, string> S;
	cin >> N >> M;
	string A,B;
	for (int i = 0;i < N;i++) {
		cin >> A >> B;
		S.insert({ A,B });
	}
	for (int i = 0;i < M;i++) {
		cin >> A;
		cout << S[A] << "\n";
	}
}