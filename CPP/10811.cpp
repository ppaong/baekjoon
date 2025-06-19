#include <iostream>
using namespace std;

void makeInverse(int &A,int &B, int* &S) {//A<B
	int* term = new int[B - A + 1];
	for (int i = 0;i <= B - A;i++)
		term[i] = S[B - 1 - i];
	for (int i = 0;i <= B - A;i++)
		S[A - 1 + i] = term[i];
	delete[]term;
}

int main(){
	int N, M;
	cin >> N >> M;
	int* S = new int[N] {0};
	int A,B,term;
	for (int i = 0;i < N;i++)
		S[i] = i + 1;
	for (int i = 0;i < M;i++) {
		cin >> A >> B;
		makeInverse(A, B, S);
	}
	for (int i = 0;i < N;i++)
		cout << S[i] << " ";
}