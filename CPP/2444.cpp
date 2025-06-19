#include <iostream>
using namespace std;

void printStar(int N);
void printLine(int length, int empty);

void printStar(int N){
    int growth = 1;
    for(int i=1;i>0;i+=growth){
        printLine(i, N-i);
        cout << endl;
        if(i>=N)
            growth=-1;
    }
}

void printLine(int length, int empty){
    for(int i=0;i<empty;i++){
        cout << " ";
    }for(int i=0;i<length*2-1;i++){
        cout << "*";
    }
}

int main()
{
    int N;
    cin >> N;
    printStar(N);
}