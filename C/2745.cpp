#include <iostream>
#include <string>
using namespace std;

int main()
{
    string N;
    int B;
    long long int V=0;
    cin >> N >> B;
    int K=B<=10?48:55; 
    for(string::iterator iter = N.begin();iter!=N.end();iter++){
        V*=B;
        V+=(int)*iter-(*iter>=65?55:48);
    }
    cout << V << endl;
    return 0;
}