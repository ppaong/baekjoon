#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    int A[N];
    int max[N+2];
    for(int i=0;i<N;i++){scanf("%d",&A[i]);max[i]=0;}
    max[N]=0;
    max[N+1]=0;
    for(int i=0;i<N-1;i++){
        if(max[i+1]<max[i])max[i+1]=max[i];
        if(max[i+2]<max[i]+A[i])max[i+2]=max[i]+A[i];
        if(max[i+3]<max[i]+A[i]+A[i+1])max[i+3]=max[i]+A[i]+A[i+1];
    }
    if(max[N]<max[N-1])max[N]=max[N-1];
    if(max[N+1]<max[N-1]+A[N-1])max[N+1]=max[N-1]+A[N-1];
    if(max[N+1]<max[N])max[N+1]=max[N];
    printf("%d",max[N+1]);
    return 0;
}

//debug

// #include<stdio.h>
// int main(){
//     int N;
//     scanf("%d",&N);
//     int A[N];
//     int max[N+2];
//     for(int i=0;i<N;i++){scanf("%d",&A[i]);max[i]=0;}
//     for(int i=0;i<N;i++)printf("%4d",i);
//     printf("\n");
//     for(int i=0;i<N;i++)printf(" %3d",A[i]);
//     printf("\n");
//     max[N]=0;
//     max[N+1]=0;
//     for(int i=0;i<N-1;i++){
//         if(max[i+1]<max[i])max[i+1]=max[i];
//         if(max[i+2]<max[i]+A[i])max[i+2]=max[i]+A[i];
//         if(max[i+3]<max[i]+A[i]+A[i+1])max[i+3]=max[i]+A[i]+A[i+1];

//         for(int j=0;j<i+1;j++)printf("    ");
//         printf(" %3d %3d %3d\n",max[i+1],max[i+2],max[i+3]);
//         for(int j=0;j<=N+1;j++)printf("%4d",max[j]);
//         printf("\n");
//     }
//     if(max[N]<max[N-1])max[N]=max[N-1];
//     if(max[N+1]<max[N-1]+A[N-1])max[N+1]=max[N-1]+A[N-1];

//     for(int j=0;j<N;j++)printf("    ");
//     printf(" %3d %3d\n",max[N],max[N+1]);

//     if(max[N+1]<max[N])max[N+1]=max[N];

//     for(int j=0;j<N+1;j++)printf("    ");
//     printf(" %3d\n",max[N+1]);

//     printf("%d",max[N+1]);
//     return 0;//O(4N)
// }