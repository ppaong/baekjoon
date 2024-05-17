#include<stdio.h>
int main(){
    int S;
    scanf("%d",&S);
    int P[S];
    int max[S];
    for(int i=0;i<S;i++){scanf("%d",&P[i]);max[i]=0;}
    max[0]=P[0];//1
    if(S<=1){printf("%d",max[0]);return 0;}
    max[1]=P[0]+P[1];//1 1
    if(S<=2){printf("%d",max[1]);return 0;}
    max[2]=P[1]+P[2];//2 1
    for(int i=0;i<S-3;i++){
        if(max[i+2]<max[i]+P[i+2])max[i+2]=max[i]+P[i+2];
        if(max[i+3]<max[i]+P[i+2]+P[i+3])max[i+3]=max[i]+P[i+2]+P[i+3];
    }
    if(max[S-1]<max[S-3]+P[S-1])max[S-1]=max[S-3]+P[S-1];
    printf("%d",max[S-1]);
    return 0;
}