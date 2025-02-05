#include <iostream>
using namespace std;

int main() {
	int N, maxX = -10000, maxY = -10000, minX = 10000, minY = 10000, X, Y;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> X >> Y;
		maxX = X > maxX ? X : maxX;
		maxY = Y > maxY ? Y : maxY;
		minX = X < minX ? X : minX;
		minY = Y < minY ? Y : minY;
	}
	cout << (maxX - minX) * (maxY - minY) << endl;
	return 0;
}