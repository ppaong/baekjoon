#include<stdio.h>
void P(int n,int m,int index,int* arr,int* squ){
    if(m==index){
        for(int i=0;i<m-1;i++){
            printf("%d ",*(squ+i));
        }
        printf("%d\n",*(squ+index-1));
        return;
    }
    for(int i=0;i<n;i++){
        *(squ+index)=*(arr+i);
        P(n,m,index+1,arr,squ);
    }
}
int main(){
    int N,M;
    int var;
    scanf("%d",&N);
    scanf("%d",&M);
    int A[N];
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
        for(int j=0;j<i;j++){
            if(A[j]==A[i]){
                N--;
                i--;
                break;
            }
            if(A[j]>A[i]){
                var=A[i];
                A[i]=A[j];
                A[j]=var;
            }
        }
    }
    int S[M];
    P(N,M,0,A,S);
    return 0;
}
