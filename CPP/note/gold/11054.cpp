#include <iostream>
using namespace std;

#define max(a,b) (a>b?a:b)

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	int V[1001];
	int MAX_V=0;
	cin >> N;
	for (int i = 1;i <= N;i++) {
		cin >> V[i];
		if (V[i] > MAX_V)
			MAX_V = V[i];
	}
	int A[1001]{0,};
	int B[1001];
	int C[1001]{0,};
	int D[1001];
	int* LR[1001];
	int* RL[1001];
	LR[0] = A;
	LR[1] = B;
	RL[0] = C;
	RL[1] = D;
	int result[1001]{ 0, };
	//r max
	for (int i = 1;i <= N;i++) {
		//LR
		for (int j = 0;j < V[i];j++)
			LR[i][j] = LR[i - 1][j];

		for (int j = V[i];j <= MAX_V;j++)
			LR[i][j] = max(LR[i - 1][V[i] - 1] + 1, LR[i - 1][j]);

		LR[i + 1] = LR[i - 1];
		result[i] += LR[i][MAX_V];
		
		//RL
		for (int j = 0;j < V[N + 1 - i];j++)
			RL[i][j] = RL[i - 1][j];

		for (int j = V[N + 1 - i];j <= MAX_V;j++)
			RL[i][j] = max(RL[i - 1][V[N + 1 - i] - 1] + 1, RL[i - 1][j]);

		RL[i + 1] = RL[i - 1];
		result[N + 1 - i] += RL[i][MAX_V];
	}

	int max_result = 0;
	for (int i = 1;i <= N;i++)
		if (result[i] > max_result)
			max_result = result[i];
	cout << max_result - 1;
}
/*
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int* V = new int[N + 1];
	map<int, int> M;
	for (int i = 1;i <= N;i++) {
		cin >> V[i];
		M[V[i]] = 0;
	}
	int count = 0;
	for (auto iter = M.begin();iter != M.end();iter++)
		iter->second = ++count;

	int* A = new int[count + 1];
	int* B = new int[count + 1];
	queue<int>** seq = new queue<int>*[count + 1];
	queue<int>* subseq = new queue<int>();
	for (int i = 0;i <= count;i++) {
		A[i] = 0;
		seq[i] = subseq;
	}
	int** dp = new int* [N + 1];
	dp[0] = A;
	dp[1] = B;
	//r max
	int p = 0;
	for (int i = 1;i <= N;i++) {
		//LR
		p = M[V[i]];
		for (int j = 0;j < p;j++)
			dp[i][j] = dp[i - 1][j];

		queue<int>* subseq = new queue<int>(*seq[p - 1]);
		subseq->push(V[i]);

		for (int j = p;j <= count;j++) {
			if (dp[i - 1][p - 1] + 1 > dp[i - 1][j]) {
				dp[i][j] = dp[i - 1][p - 1] + 1;
				seq[j] = subseq;
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
		dp[i + 1] = dp[i - 1];
	}
	int k = 0;
	for (;;) {
		k += seq[count]->front();
		seq[count]->pop();
		if (seq[count]->empty())
			break;
	}
	cout << k;
}


*/
/*
ex)
	순방향
	K=>  0 1 2 3 4 5
	0    0 0 0 0 0 0
	1    0 1 1 1 1 1 
	5    0 1 1 1 1 2
	2    0 1 2 2 2 2
	1    0 1 2 2 2 2
	4    0 1 2 2 3 3
	3    0 1 2 3 3 3
	4    0 1 2 3 4 4
	5    0 1 2 3 4 5
	2    0 1 2 3 4 5
	1    0 1 2 3 4 5

	역방향
	K=>  0 1 2 3 4 5
	1    0 1 1 1 1 1
	2    0 1 2 2 2 2
	5    0 1 2 2 2 3
	4    0 1 2 2 3 3
	3    0 1 2 3 3 3
	4    0 1 2 3 4 4
	1    0 1 2 3 4 4
	2    0 1 2 3 4 4
	5    0 1 2 3 4 5
	1    0 1 2 3 4 5
*/