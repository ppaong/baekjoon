#include <iostream>
using namespace std;

int main()
{
    int A,B;
    for(;;){
        cin>>A>>B;
        if(A==0&&B==0)
            break;
        if(A!=1&&B!=1&&(A<B?B%A==0:A%B==0))
            cout<<(A<B?"factor":"multiple")<<endl;
        else
            cout<<"neither"<<endl;
    }
    return 0;
}