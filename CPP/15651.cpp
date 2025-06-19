#include <iostream>
using namespace std;
//중복수열
void sequence(int N, int M,int &L, int* in, int* out) {
	if (M != 0) {
		for (int i = 0;i < N;i++) {
			out[M] = in[i];
			sequence(N, M - 1, L, in, out);
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
	for (int i = 0;i < N;i++)
		S[i] = i + 1;
	sequence(N, M, M, S, new int[M + 1]);
}