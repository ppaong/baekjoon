#include <iostream>
#include <string>
using namespace std;

bool isFail(string &str){
    return *(str.end()-1)=='F';
}
bool isPass(string &str){
    return *(str.end()-1)=='P';
}

double getGrade(string &str){
    if(isFail(str)||isPass(str))
        return 0;
    string::iterator iter = str.end()-2;
    return (69-(int)*iter)+(*(iter+1)=='+'?0.5f:0);
}
double getCredit(string &str){
    if(isPass(str))
        return 0;
    string::iterator iter = str.end()-6;
    if(isFail(str)) iter++;
    return ((int)*iter-48)+((int)*(iter+2)-48)*0.1f;
}


int main()
{
    string line;
    double creditSum=0,gradeSum=0;
    double credit;
    for(int i=0;i<20;i++){
        getline(cin, line, '\n');
        //cout << getCredit(line) << " : " << getGrade(line) << endl;
        credit=getCredit(line);
        creditSum+=credit;
        gradeSum+=getGrade(line)*credit;
    }
    cout.precision(6);
    cout << fixed;
    cout << gradeSum/creditSum;
    return 0;
}