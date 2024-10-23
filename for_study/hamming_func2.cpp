#include <iostream>
#include <string>
using namespace std;

string toLowerStr(string str){
    string newstr=str;
    for (char &c : newstr){
        c=tolower(c);
    }
    return newstr;
}
string toUpperStr(string str){
    string newstr=str;
    for (char &c : newstr){
        c=toupper(c);
    }
    return newstr;
}
int calHammingDist(string str1, string str2){
    str1=toLowerStr(str1);
    str2=toLowerStr(str2);
    int count = 0;
    for (int i=0; i < str1.length(); i++){
        if (str1[i] != str2[i]){
            count +=1;
        }
    }
    return count;
}
int main(){
    string s1,s2;
    while(1){
        cout << "DNA1: ";
        cin >> s1;
        cout << "DNA2: ";
        cin >> s2;

        if (s1.length() != s2.length()){
            cout <<"오류: 길이가 다름" << endl;
            continue;
        }
        else{
            int count = calHammingDist(s1,s2);
            cout <<"해밍 거리는"<<count<<endl;
            break;
        }
    }
    

    return 0;
}