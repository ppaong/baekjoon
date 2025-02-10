#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N,M;
	cin >> N;
	vector<int> P;
	for (int i = 0;i < N;i++) {
		cin >> M;
		if (M < 2)
			cout << (M < 1 ? "1 0\n" : "0 1\n");
		else {
			P.push_back(0);
			P.push_back(1);
			for (int k = 2;k < M;k++)
				P.push_back(*(P.end() - 2) + P.back());
			cout << P.back() << " " << *(P.end() - 2) + P.back() << "\n";
		}
		P.clear();
	}
}