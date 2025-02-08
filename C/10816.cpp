#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	unordered_map<int, int> S;
	int N;
	cin >> N;
	int term;
	for (int i = 0;i < N;i++) {
		cin >> term;
		S[term]++;
	}
	int M;
	cin >> M;
	for (int i = 0;i < M;i++) {
		cin >> term;
		cout << S[term] << " ";
	}
}
