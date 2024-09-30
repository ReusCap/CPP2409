#include <iostream>
using namespace std;

int main() {
    int floor;
    cout <<"몇 층을 쌓겠습니까? (5~100):";
    cin >> floor;
    for (int i=0; i<floor ; i++){   // 조건식 범위를 i--가 아니라 i++이도록 바꿨다.
        for(int j=0; j<i; j++){     // 조건식 범위 변경
            cout <<"S";
        }
        for(int k=0; k < ((floor-i)*2-1); k++){ //조건식 범위 변경
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}