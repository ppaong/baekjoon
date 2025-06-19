#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string target){
    string::iterator front = target.begin();
    string::iterator back = --target.end();
    for(int i=0;i<target.length()/2;i++){
        if(*front++!=*back--)
            return false;
    }
    return true;
}

int main()
{
    string input;
    cin >> input;
    cout << isPalindrome(input)?1:0;
}