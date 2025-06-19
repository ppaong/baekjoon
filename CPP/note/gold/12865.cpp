#include <iostream>
using namespace std;

//#define gt(a,b) ((a)>(b)?(a):(b))  이런거 쓰는것도 있다 하더라

int main() {

    int N, K;
    cin >> N >> K;

    long long** dp = new long long* [N + 2];
    dp[0] = new long long[K+1] {0,};
    dp[1] = new long long[K+1];

    int W, V;
    for (int i = 1;i <= N;i++) {
        cin >> W >> V;
        for (int j = 0;j <= K;j++) {
            if (j >= W && V + dp[i - 1][j - W] > dp[i - 1][j])
                dp[i][j] = V + dp[i - 1][j - W];
            else
                dp[i][j] = dp[i - 1][j];
        }
        dp[i + 1] = dp[i - 1];
    }
    cout << dp[N][K];
}