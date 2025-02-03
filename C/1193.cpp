#include <iostream>
using namespace std;

int main()
{
    int X;
    cin >> X;
    int N;
    int T;
    for(int i=1;;i++){
        if(X<=(i*(i+1))/2){
            N=i;
            T=X-(i*(i-1))/2;
            break;
        }
    }
    //cout << N << " : " << T << endl;
    if(N%2==0)
        cout << T << "/" << N-T+1 << endl;
    else
        cout << N-T+1 << "/" << T << endl;

    return 0;
}