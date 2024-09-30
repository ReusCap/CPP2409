#include <iostream>
using namespace std;

int main() {
    int floor;
    cout <<"몇 층을 쌓겠습니까? (5~100):";
    cin >> floor;
    for (int i=1; i<=floor ; i++){  //초기식을 1부터 floor까지로 설정했다.
        for(int j=0; j<floor-i; j++){
            cout <<"S";
        }
        for(int k=0; k<i*2-1; k++){
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}