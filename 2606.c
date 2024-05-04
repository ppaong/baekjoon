#include<stdio.h>
int main(){
    int C,P;
    scanf("%d",&C);
    scanf("%d",&P);
    int U[P][2];//노드쌍
    for(int k=0;k<P;k++) scanf("%d %d",&U[k][0],&U[k][1]);
    int L[C];//방문 노드
    L[0]=1;
    int n=1;
    for(int s=0;s<n;s++){
        for(int i=0;i<P;i++){
            if(U[i][0]==L[s]||U[i][1]==L[s]){//방문 노드랑 연결된 노드 발견시
                L[n]=U[i][0]!=L[s]?U[i][0]:U[i][1];//연결된 노드 방문처리
                for(int k=0;k<n;k++) if(L[k]==L[n]) L[n--]=0;//이미 방문한거면 무효처리
                n++;
                U[i][0]=U[P-1][0];//가장 끝 쌍으로 바꾸기
                U[i][1]=U[P-1][1];
                P--;//쌍 갯수 감소
                i--;//본 쌍 부터 재 검사
            }
        }
    }
    printf("%d",n-1);
    return 0;
}