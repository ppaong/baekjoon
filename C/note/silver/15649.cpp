#include <iostream>
using namespace std;
//15654 same solution
void sequence(int N, int M,int &L, int* in, int* out) {
	if (M != 0) {
		int* term = new int[N - 1];
		int P;
		for (int i = 0;i < N;i++) {
			out[M] = in[i];
			P = 0;
			for (int k = 0;k < i;k++)
				term[P++] = in[k];
			for (int k = i + 1;k < N;k++)
				term[P++] = in[k];
			sequence(N - 1, M - 1, L, term, out);
		}
		delete[] term;
	}
	else {
		for (int i = L;i > 1;i--)
			cout << out[i] << " ";
		cout << out[1] << "\n";
	}
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int* S = new int[N];
	for (int i = 0;i < N;i++)
		S[i] = i + 1;
	sequence(N, M, M, S, new int[M+1]);
}

/*
#include <iostream>
using namespace std;

void sequence(int N, int M,int &L, int* in,int** term, int* out) {
	if (M != 0) {
		int P;
		for (int i = 0;i < N;i++) {
			out[M] = in[i];
			P = 0;
			for (int k = 0;k < i;k++)
				term[N - 1][P++] = in[k];
			for (int k = i + 1;k < N;k++)
				term[N - 1][P++] = in[k];
			sequence(N - 1, M - 1, L, term[N - 1], term, out);
		}
	}
	else {
		for (int i = L;i > 1;i--)
			cout << out[i] << " ";
		cout << out[1] << "\n";
	}
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int* S = new int[N];
	int** term = new int* [N];
	for (int i = 0;i < N;i++) {
		S[i] = i + 1;
		term[i] = new int[i + 1];
	}
	sequence(N, M, M, S, term, new int[M + 1]);
}
*/