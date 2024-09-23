#include <iostream>
using namespace std;

int main(){
    int a,b,c,largest;

    cout << "3개의 정수를 입력하시오: ";
    cin >> a >> b >> c;

    // 최종 문장 출력을 조건문 안에서 각각 출력 하도록 변경했다.
    if (a == b && a == c){  // a, b, c 세 수가 모두 같은 경우를 조건 추가.
        largest = a;
        cout << "세 수가 모두 같고 정수는"<< largest << endl;
    }
    else if(a == b && a > c){ // a와 b가 같고 제일 큰 경우 조건 추가.
        largest = a;
        cout << "a와 b가 같고 c보다 크다. 가장 큰 정수는"<< largest << endl;
    }
    else if(a == c && a > b){ // a와 c가 같고 제일 큰 경우 조건 추가.
        largest = a;
        cout << "a와 c가 같고 b보다 크다. 가장 큰 정수는"<< largest << endl;
    }
    else if(b == c && b > a){ // b와 c가 같고 제일 큰 경우 조건 추가.
        largest = a;
        cout << "b와 c가 같고 a보다 크다. 가장 큰 정수는"<< largest << endl;
    }
    else if(a > b && a > c){
        largest = a;
        cout << "가장 큰 정수는"<< largest << endl;
    }
    else if(b > a && b > c){
        largest = b;
        cout << "가장 큰 정수는"<< largest << endl;
    }
    else{
        largest = c;
        cout << "가장 큰 정수는"<< largest << endl;
    }
    return 0;
}