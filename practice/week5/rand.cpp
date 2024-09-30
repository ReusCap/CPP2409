#include <iostream>
using namespace std;

int main() {
    int list[10];
    int max;

    for (int i=0; i<10; i++){
        int elem = rand() % 100 +1; // 1부터 100까지 난수 생성
        list[i]=elem;
        cout << elem << " ";
    }
    cout << endl;
    max = list[0];
    for(auto elem : list){
        if (elem > max){
            max = elem;
        }
    }
    cout <<"최대값=" << max << endl;
    return 0;
}