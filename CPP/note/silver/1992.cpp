#include <iostream>
#include <string>
using namespace std;
using std::cout;

char field[64][64];
string result[64][64];

bool f(int x, int y, int n) {
	if (n <= 1)
		return true;
	
	n >>= 1;
	bool a = f(x, y, n);
	bool b = f(x + n, y, n);
	bool c = f(x, y + n, n);
	bool d = f(x + n, y + n, n);
	if (a && b && c && d && (field[x][y] == field[x + n][y]) && (field[x + n][y] == field[x][y + n]) && (field[x][y + n] == field[x + n][y + n]))
		return true;

	else {
		string str;
		str += '(';
		str += result[x][y];
		str += result[x + n][y];
		str += result[x][y + n];
		str += result[x + n][y + n];
		str += ')';

		result[x][y] = str;
		return false;
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	string str;
	for (int i = 0;i < N;i++) {
		cin >> str;
		for (int j = 0;j < N;j++){
			field[j][i] = str[j];
			result[j][i] += str[j];
		}
	}
	
	int a = f(0, 0, N);
	cout << result[0][0];
}
