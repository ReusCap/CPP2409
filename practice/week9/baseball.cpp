#include <iostream>
#include <string>
using namespace std;

bool numCheck(int first, int second, int third){
	if ((first != second) && (first != third) && (second != third)){
		return true;
	}else{
		return false;
	}
}

int main() {
	int randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수
	int firstNum; // 정답의 첫번째 자리수
	int secondNum; // 정답의 두번째 자리수
	int thirdNum; // 정답의 세번째 자리수

	while (1) {		
		randomNum = rand() % 900 + 100; // 랜덤한 3자리수 생성

		bool same = false; // 모든 수가 다를 경우 true를 갖는 변수

		// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
        // 정수 특성을 이용해서 각 자릿수 나누기와 나머지 연산으로 구한다.
		string ranStr = to_string(randomNum);
        firstNum = ranStr[0] - '0';
        secondNum = ranStr[1] - '0';
        thirdNum = ranStr[2] - '0';
        
        // 1과 2, 1과 3, 2와 3이 다른 여부를 파악 후 same=true로 바꾼다.
        same=numCheck(firstNum, secondNum, thirdNum);

		if (same == true) {
			break;
		}
	}

	int turn = 0;
	while (1) {
		cout << turn + 1 << "번째 시도입니다. " << endl;

		// 012나 001을 입력받았을 때 userNumber.length()에 영향을 주지 않도록 string으로 받도록 바꿈
		string userNumber; // 사용자가 입력한 세자리수 저장 변수
		int guessFirst; // 추측한 숫자의 첫번째 자리수
		int guessSecond; // 추측한 숫자의 두번째 자리수
		int guessThird; // 추측한 숫자의 세번째 자리수


		// 사용자에게 세자리 수를 입력받는 코드 블록
		while (1) {
			cout << "세자리 수를 입력해주세요: ";
			cin >> userNumber;

			bool same = false; // 모든 수가 다를 경우 true를 갖는 변수
			// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성'

            // 정수형 특성을 이용해서 '0' 값을 빼준다.
            guessFirst = (int)userNumber[0]-'0';
            guessSecond = (int)userNumber[1]-'0';
            guessThird = (int)userNumber[2]-'0';

            // numCheck 함수사용
			same = numCheck(guessFirst, guessSecond, guessThird);

			// userNumber을 string으로 받았어서 userNumber.length()로 길이 판단
			// 이래서 012나 001 입력해도 3자리로 인식하고 넘어갑니다.
			if (userNumber.length()!= 3) {
				cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
				continue;
			}
            if(same == false){
                cout<< "입력한 숫자에 중복된 숫자가 있습니다. 다시 입력하세요."<< endl;
                continue;
            }

			if (same == true) {
				break;
			}
		}

		int strike = 0; // 스트라이크 갯수를 저장하는 변수
		int ball = 0; // 볼 갯수를 저장하는 변수

		// TODO 2: 정답과 추측한 숫자의 자릿수와 숫자를 비교하며 힌트를 주기 위한 코드블록 작성
		// if와 else if로 확인
        if (guessFirst==firstNum){
            strike+=1;
        }else if ((guessFirst==secondNum) || (guessFirst==thirdNum)){
            ball+=1;
        }
        if (guessSecond==secondNum){
            strike+=1;
        }else if ((guessSecond==firstNum) || (guessSecond==thirdNum)){
            ball+=1;
        }
        if (guessThird==thirdNum){
            strike+=1;
        }else if ((guessThird==firstNum) || (guessThird==secondNum)){
            ball+=1;
        }
	
		cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << "볼 입니다." << endl;
		
		if (strike == 3) {
			cout << "정답을 맞췄습니다. 축하합니다.";
			break;
		}

		turn += 1;
	}

	return 0;
}
