#include <iostream>
using namespace std;

int sum = 0;
void search(int& N, int A, int* R, int sizeR, int* L, int sizeL, bool* M) {
	/*
	cout <<"===========" << N << " " << A << "\n";
	for (int i = 0;i < sizeR;i++)
		cout << R[i] << " ";
	cout << "\n";
	for (int i = 0;i < sizeL;i++)
		cout << L[i] << " ";
	cout << "\n";
	*/
	if (A < N) {
		bool* check = new bool[N] {false};
		int* termR = new int[sizeR + 1] {0};
		int PR = 0;
		int* termL = new int[sizeL + 1] {0};
		int PL = 0;
		for (int k = 0;k < sizeR;k++) {//R
			check[R[k]] = true;
			if (R[k] + 1 < N)
				termR[PR++] = R[k] + 1;
		}
		for (int k = 0;k < sizeL;k++) {//L
			check[L[k]] = true;
			if (L[k] - 1 >= 0)
				termL[PL++] = L[k] - 1;
		}
		/*
		for (int i = 0;i < N;i++)
			cout << M[i] << " ";
		cout << "\n";
		for (int i = 0;i < N;i++)
			cout << check[i] << " ";
		cout << "\n";
		*/
		//int count = 0;
		for (int i = 0;i < N;i++) {//X
			if (!check[i] && !M[i]) {//M
				//count++;
				//cout << ">queen on " << i << "," << A << "\n";
				if (i + 1 < N)
					termR[PR] = i + 1;
				if (i - 1 >= 0)
					termL[PL] = i - 1;
				M[i] = true;
				search(N, A + 1, termR, PR + (i + 1 < N ? 1 : 0), termL, PL + (i - 1 >= 0 ? 1 : 0), M);
				M[i] = false;
			}
		}
		//if (count == 0)
			//cout << "NO SOLUTION\n";
		delete[] termR;
		delete[] termL;
		delete[] check;
	}
	else {
		sum++;
		//cout << "COMPLETE\n";
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	search(N, 0, new int[0], 0, new int[0], 0, new bool[N] {false});
	cout << sum;
}