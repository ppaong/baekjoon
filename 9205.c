#include<stdio.h>
void edgeMaking(int a[2],int x,int y){a[0]=x;a[1]=y;}//a(?,?)=(x,y) 처리
void edgeInitialization(int a[2],int b[2]){edgeMaking(a,b[0],b[1]);}//a(x1,y1)=b(x2,y2) 처리
int edgeConnection(int n,int e[2]){return e[0]==n?e[1]:e[1]==n?e[0]:0;}//if "n in e(x,y)" 이면 나머지원소 반환 else 0
int abs(int n){return n>0?n:-n;}//n의 절댓값 반환
int distance(int a[2],int b[2]){return abs(b[0]-a[0])+abs(b[1]-a[1]);}//a(x1,y1),b(x2,y2) 의 멘해튼 거리 반환
int main(){
    int T,N,var;
    scanf("%d",&T);
    for(int k=0;k<T;k++){
        scanf("%d",&N);
        int P[N+2][2];//p(x,y) 노드 번호:상근이네=0,~,페스티벌=N+1 
        int E[(N+2)*(N+3)/2][2];//edge
        int e=0;//edge count
        for(int i=0;i<N+2;i++){
            scanf("%d",&P[i][0]);
            scanf("%d",&P[i][1]);
            for(int j=0;j<i;j++){
                if(distance(P[j],P[i])<=1000)
                    edgeMaking(E[e++],j,i);
            }
        }
        int Q[N+2];//queue
        Q[0]=0;//0=상근이네
        int q=1;//queue count
        for(int i=0;i<q;i++){//queue 길이 만큼
            for(int j=0;j<e;j++){//edge 길이 만큼
                if(var=edgeConnection(Q[i],E[j])){//방문중인 노드랑 연결되있으면 var는 연결된 노드번호가 되고 if문 실행
                    if(var==N+1){printf("happy\n"); goto END;}//패스티벌 도착
                    Q[q++]=var;//노드번호 enqueue
                    for(int l=0;l<q-1;l++)if(Q[l]==var){q--;break;}//queue 중복처리
                    edgeInitialization(E[j--],E[--e]);//지나온 edge 삭제
                }
            }
        }
        printf("sad\n");
END:;
    }
    return 0;
}