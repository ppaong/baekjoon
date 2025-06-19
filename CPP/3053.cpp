#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N;
	vector<int> R(0);
	for (int i = 0;i < 10;i++) {
		cin >> N;
		R.push_back(N % 42);
	}
	for (int i = 0;i < R.size();i++) {
		for (int j = i+1;j < R.size();j++) {
			if (R[i] == R[j])
				R.erase(R.begin() + j--);
		}
	}
	cout << R.size();
}