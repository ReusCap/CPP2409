#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    do{
        getline(cin,str);
        cout  << str << endl;
    }while(str != "finish");
    return 0;
}