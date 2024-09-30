#include <iostream>
#include <string>
using namespace std;

int main() {
    const int maxPeople = 5;
    string names[maxPeople];
    int ages[maxPeople];

    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;

    for (int i = 0; i < maxPeople; i++) {
        cout << "사람" << i + 1 << "의 이름: ";
        cin >> names[i];
        cout << "사람" << i + 1 << "의 나이: ";
        cin >> ages[i];
    }

    int older = 0; 
    int younger = 0;
    for (int i = 0; i < maxPeople; i++) {
        if (ages[i] >= ages[older]) {
            older = i;
        }
    }
    for (int i = 0; i < maxPeople; i++) {
        if (ages[i] <= ages[younger]) {
            younger = i;
        }
    }

    int select;
    bool flag = true;  // flag 선언 및 초기값 설정

    while (flag) {  // flag가 true일 때 루프 실행
        cout << "1. 가장 나이가 많은 사람 출력" << endl;
        cout << "2. 가장 나이가 적은 사람 출력" << endl;
        cout << "3. 종료" << endl;
        cin >> select;
        switch (select) {
            case 1:
                cout << "가장 나이가 많은 사람은 ";
                for (int i = 0; i < maxPeople; i++) {   // if문으로 ages[older]값과 동일한 값들을 출력
                    if (ages[i] == ages[older]) {
                        cout << names[i] << " ";
                    }
                }
                cout<< endl;
                break;
            case 2:
                cout << "가장 나이가 적은 사람은 ";
                for (int i = 0; i < maxPeople; i++) {   // if문으로 ages[younger]값과 동일한 값들을 출력
                    if (ages[i] == ages[younger]) {
                        cout << names[i] << " ";
                    }
                }
                cout<< endl;
                break;
            case 3:
                cout << "종료" << endl;
                flag = false;  // flag를 false로 설정하여 루프 종료
                break;
            default:
                cout << "잘못된 입력입니다. 종료합니다." << endl;
                flag = false;  // 잘못된 입력 시에도 루프 종료
        }
    }

    return 0;
}
