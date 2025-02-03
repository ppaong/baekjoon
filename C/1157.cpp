#include <iostream>
#include <string>
#include <map>
using namespace std;

char makeCapital(char letter){
    return 'a'<=letter?letter-32:letter;
}

char findFrequentAlphabet(string str){
    //if(str.length()==1) return makeCapital(str[0]);
    map<char, int> m;
    char targetLetter;
    for(string::iterator iter = str.begin();iter!=str.end();iter++){
        targetLetter = makeCapital(*iter);
        if(m.find(targetLetter)!=m.end())
            m[targetLetter]++;
        else
            m.insert({targetLetter,1});
    }
    bool repetition = false;
    for(map<char, int>::iterator iter=m.begin();iter!=m.end();iter++){
        //cout << iter->first << " : "<< iter->second << endl;
        if(m[targetLetter]<iter->second){
            targetLetter = iter->first;
            repetition = false;
        }
        else if(targetLetter!=iter->first&&m[targetLetter]==iter->second){
            repetition = true;
        }
    }
    return repetition?'?':targetLetter;
}

int main()
{
    string input;
    cin >> input;
    cout << findFrequentAlphabet(input);
}