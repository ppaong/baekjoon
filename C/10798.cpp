#include <iostream>
using namespace std;

int main(){
	string W[5];
	int maxL = 0;
	for (int i = 0;i < 5;i++) {
		cin >> W[i];
		if (W[i].length() > maxL)
			maxL = W[i].length();
	}
	int term;
	for (int i = 0;i < 5;i++) {
		term = maxL - W[i].length();
		for (int j = 0;j < term;j++)
			W[i].push_back(' ');
	}
	for (int j = 0;j < maxL;j++) {
		for (int i = 0;i < 5;i++) {
			if(W[i][j]!=' ')
				cout << W[i][j];
		}
	}
}