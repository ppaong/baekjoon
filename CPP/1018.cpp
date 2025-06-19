#include <iostream>
using namespace std;

int absForBoard(int A) {
	return A < 64 - A ? A : 64 - A;
}

int getRowMin(int &A,int* &line) {
	int sum = 0;
	for (int i = 0;i < 8;i++)
		sum += line[i];
	int min = absForBoard(sum);
	//cout << sum << " ";
	for (int i = 0;i < A - 8;i++) {
		sum += line[i + 8] - line[i];
		if (absForBoard(sum) < min)
			min = absForBoard(sum);
		//cout << sum << " ";
	}
	//cout <<"row min : " << min << "\n";
	return min;
}

int getMin(int &A, int &B,bool** &board) {
	int* line = new int[A] {0};
	for (int i=0;i < A;i++)
		for (int j = 0;j < 8;j++)
			line[i] += (int)board[i][j];

	int sum = getRowMin(A, line);
	int min = absForBoard(sum);
	for (int j = 0;j < B - 8;j++) {
		for (int i = 0;i < A;i++)
			line[i] += (int)board[i][j + 8] - (int)board[i][j];
		sum=getRowMin(A, line);
		if (absForBoard(sum) < min)
			min = absForBoard(sum);
	}
	return min;
}

//W=T B=F
int main() {
	int A, B;
	cin >> A >> B;
	bool** boardA = new bool* [A];
	char txt;
	bool isWhite;
	for (int i = 0;i < A;i++) {
		boardA[i] = new bool[B];
		for (int j = 0;j < B;j++) {
			cin >> txt;
			isWhite = (txt == 'W');
			boardA[i][j] = (isWhite && (i + j) % 2 == 0) || (!isWhite && (i + j) % 2 == 1);
		}
	}
	/*cout << "-----------------W\n";
	for (int i = 0;i < A;i++) {
		for (int j = 0;j < B;j++) {
			cout << (int)boardA[i][j];
		}
		cout << "\n";
	}
	cout << "-----------------\n";*/
	int min = getMin(A, B, boardA);
	cout << min;
}
