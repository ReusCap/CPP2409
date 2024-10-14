#include <iostream>
#include <string>
using namespace std;

string toLowerStr(string str){
    for (char &c : str){
        c=tolower(c);
    }
    return str;
}
string toUpperStr(string str){
    for (char &c : str){
        c=toupper(c);
    }
    return str;
}
int calHammingDist(string str1, string str2){
    int count = 0;
    if(str1.length() != str2.length()){
        cout <<"오류: 길이가 다름"<< endl;
    }
    else{
        for (int i=0; i < str1.length(); i++){
            if (str1[i] != str2[i]){
                count +=1;
            }
        }
    }
    return count;
}
int main(){
    string s1="MisooKim", s2="misookim";
    s1=toLowerStr(s1);
    s2=toLowerStr(s2);
    int count=calHammingDist(s1,s2);
    cout <<"해밍 거리는 " << count << endl;
    


}