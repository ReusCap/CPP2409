// 문자열끼리만 합칠 수 있지 문자는 못합침
// char은 ''만 가능 "" 불가능
// to_string() 함수로 string으로 변경 가능
#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1="Good";
    string s2="Morning";
    string s3=s1+" " + s2+ "!";
    cout << s3 << endl;
    return 0;
}