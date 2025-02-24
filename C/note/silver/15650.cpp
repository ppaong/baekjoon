#include <iostream>
using namespace std;
//조합 내림차순
void sequence(int N, int M, int& L, int* in, int** term, int* out) {
	if (M != 0) {
		int P;
		for (int i = 0;i < N - M + 1;i++) {
			out[M] = in[i];
			P = 0;
			for (int k = i + 1;k < N;k++)
				term[N - i - 1][P++] = in[k];
			sequence(N - i - 1, M - 1, L, term[N - i - 1], term, out);
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