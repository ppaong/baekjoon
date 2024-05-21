#include<stdio.h>
int edgeConnection(int n,int e[2]){
    return e[0]==n?e[1]:e[1]==n?e[0]:0;
}
int abs(int n){
    return n>0?n:-n;
}
int distance(int a[2],int b[2]){
    return abs(b[0]-a[0])+abs(b[1]-a[1]);
}
int main(){
    int T,N,var;
    scanf("%d",&T);
    for(int k=0;k<T;k++){
        scanf("%d",&N);
        int P[N+2][2];//P[0]=상근이네,P[N+1]=락 페스티벌
        int E[(N+2)*(N+3)/2][2];
        int e=0;
        for(int i=0;i<N+2;i++){
            scanf("%d",&P[i][0]);
            scanf("%d",&P[i][1]);
            for(int j=0;j<i;j++){
                if(distance(P[j],P[i])<=1000){
                    E[e][0]=j;
                    E[e][1]=i;
                    e++;
                    //InitializePair(E[e++],j,i);
                }
            }
        }
        int Q[N+2];
        Q[0]=0;
        int q=1;
        for(int i=0;i<q;i++){
            for(int j=0;j<e;j++){
                var=edgeConnection(Q[i],E[j]);
                if(var){
                    if(var==N+1){
                        printf("happy\n");
                        goto END;
                    }
                    Q[q]=var;
                    for(int l=0;l<q;l++)if(Q[l]==var){q--;break;}
                    q++;
                    e--;
                    E[j][0]=E[e][0];
                    E[j][1]=E[e][1];
                    j--;
                    //InitializePair(E[j--],E[--e]);
                }
            }
        }
        printf("sad\n");
END:;
    }
    return 0;
}