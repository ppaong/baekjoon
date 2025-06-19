#include<stdio.h>
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int N,M;
    scanf("%d",&N);
    scanf("%d",&M);
    int m[N];
    int c[N];
    for(int i=0;i<N;i++)scanf("%d",&m[i]);
    for(int i=0;i<N;i++)scanf("%d",&c[i]);

    int dp[N+1][10001];
    for(int i=0;i<=N;i++)for(int j=0;j<=10000;j++)dp[i][j]=0;

    for(int i=0;i<N;i++){
        dp[i+1][c[i]]=dp[i][0]+m[i];
        for(int j=0;j<=10000;j++){
            if(dp[i][j]){
                dp[i+1][j+c[i]]=max(dp[i][j]+m[i],dp[i+1][j+c[i]]);
                dp[i+1][j]=max(dp[i][j],dp[i+1][j]);
            }
        }
    }
    for(int i=0;i<=10000;i++){
        if(dp[N][i]>=M){
            printf("%d",i);
            break;
        }
    }
    return 0;
}
