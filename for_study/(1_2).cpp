#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int main(){
    int num=72;
    string numstr = to_string(num);
    cout << numstr << endl;
    cout << numstr[0] << " " << numstr[1] << endl;

    // (int)numstr로 형변환
    int firstnum = (int)numstr[0];
    cout << firstnum;

    return 0;

}
