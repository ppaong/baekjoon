#include <iostream>
#include <map>
using namespace std;

int main() {
	int N;
	cin >> N;
	int* S = new int[N];
	map<int, int> L;
	int term;
	for (int i = 0;i < N;i++) {
		cin >> term;
		S[i] = term;
		L.insert({ term,0 });
	}
	int count=0;
	for (map<int, int>::iterator iter = L.begin();iter != L.end();iter++)
		iter->second = count++;
	for (int i = 0;i < N;i++)
		cout << L[S[i]] << " ";
}