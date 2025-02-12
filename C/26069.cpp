#include <iostream>
#include <set>
using namespace std;

int main() {
	set<string> S;
	S.insert("ChongChong");
	int N;
	cin >> N;
	string A, B;
	bool infection = false;
	for (int i = 0;i < N;i++) {
		cin >> A >> B;
		if (S.find(A) != S.end()) {
			S.insert(B);
		}
		else if (S.find(B) != S.end()) {
			S.insert(A);
		}
	}
	cout << S.size();
}
