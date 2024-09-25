// cin >> ch를 while조건으로 넣으면 사용자에게 값을 입력받으면서, 입력받으면 true, 입력 안받으면 false가 반환, ctrl+z는 입력 안하는 단축키
#include <iostream>
using namespace std;

int main(){
    int vowel = 0;
    int consonant =0;
    cout <<"영문자를 입력하고 ctr+z를 치세요" << endl;

    char ch; // 사용자 입력 저장하기 위한 변수
    while(cin >> ch){   // ctrl+z를 입력하면  false가 되게 조건설정
        switch (ch){
            case 'a':
                vowel++;
                break;
            case 'e':
                vowel++;
                break;
            case 'i':
                vowel++;
                break;
            case 'o':
                vowel++;
                break;
            case 'u':
                vowel++;
                break;
            default:
                consonant++;
        }
    }
    cout <<"모음: " << vowel << endl;
    cout <<"자음: " << consonant << endl;

    return 0;
}