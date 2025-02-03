#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N;
    cin >> N;
    long long int P = pow(4,N)+pow(2,N+1)+1;
    cout << P << endl;
    return 0;
}