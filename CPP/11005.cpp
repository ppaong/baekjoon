#include <iostream>
#include <string>
using namespace std;

char NumberToNDigit(int number,int N){
    if(number<=10)
        return (char)(number+48);
    else
        return (char)(number+55);
}

int main()
{
    int N,B;
    cin >> N >> B;
    string str = "";
    for(int i=0;;i++){
        str.insert(0,1,NumberToNDigit(N%B,B));
        if(N<B) break;
        N/=B;
    }
    cout << str << endl;
    return 0;
}