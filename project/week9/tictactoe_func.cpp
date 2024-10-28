#include <iostream>
using namespace std;
    // 매개변수들을 전역변수 설정
	const int numCell = 5; // 보드판의 가로 세로 길이
// 입력받은 코드 유효성 검사
bool isValid(int x,int y, char board[numCell][numCell]){
    if (x >= numCell || y >= numCell) {// 좌표 범위를 벗어날때
        cout << x << "," << y << ": x와 y 둘 중 하나가 칸을 벗어납니다. " << endl;
        return false;
    }
    if (board[x][y] != ' ') {// 좌표범위의 입력값이 중복될때
        cout << x << "," << y << ": 이미 돌이 차있습니다. " << endl;
        return false;
    }
    return true;
}
// 가로 세로 승리 조건 함수
bool checkWin(char currentUser, char board[numCell][numCell]){
	for (int i = 0; i < numCell; i++) {
        bool rowWin = true, colWin = true;	// 각 i가 정해질때 rowwin과 colwin을 초기화
        for (int j = 0; j < numCell; j++) {
            if (board[i][j] != currentUser){
				rowWin = false;  // 가로 체크
			}if (board[j][i] != currentUser){
				colWin = false;  // 세로 체크
			} 
        }
        if (rowWin || colWin) {
			return true;  // 가로 또는 세로에서 하나라도 true이면 true반환
		}
    }
	return false;
}


int main() {
	// 게임을 진행하는 데 필요한 변수 선언

	char board[numCell][numCell]{}; // 보드판을 나타내는 2차원 배열
	char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 변수
	int k = 0; // 누구 차례인지 체크하기 위한 변수
	int x, y = 0; // 사용자에게 xy좌표값을 입력받기 위한 변수

	// 보드판 초기화
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	// 게임을 무한 반복
	while (true) {
		// 1. 누구 차례인지 출력
		// TODO 1.1: 3인용 게임으로 변경
		switch (k % 3) {
		case 0:
			currentUser = 'X';
			break;
		case 1:			
			currentUser = 'O';
			break;
        case 2:			
			currentUser = 'H';
			break;
		}
		cout << k % 3 + 1 << "번 유저("<< currentUser <<")의 차례입니다. -> ";

		// 2. 좌표 입력 받기
		cout << "(x, y) 좌표를 입력하세요: ";
		cin >> x >> y;
		// 3. 입력받은 좌표의 유효성 체크
		// TODO FUNC 1: isValid 함수 생성 후 호출
        // 위에 생성한 함수를 호출
		if (isValid(x,y, board) == false){
            continue;	
        }

		// 4. 입력받은 좌표에 현재 유저의 돌 놓기
		board[x][y] = currentUser;

		// 5. 현재 보드 판 출력
		// TODO 1.2: numCell 숫자에 맞춘 보드판 출력
		for (int i = 0; i < numCell; i++) {
            // for문으로 numCell-1까지 "---|"를 출력하고
            // 그 다음에 "---"을 출력하는 방식 사용
            for(int k=0;k<numCell-1; k++){
                cout << "---|";
            }
            cout << "---" << endl;
			for (int j = 0; j < numCell; j++)
			{
				cout << board[i][j];
				if (j == numCell - 1) {
					break;
				}
				cout << "  |";
			}
			cout << endl;
		}
        // 여기도 마찬가지로 사용
		for(int k=0;k<numCell-1; k++){
                cout << "---|";
            }
        cout << "---" << endl;


		bool isWin = false; // 승리 여부
		// TODO FUNC2: 6.1부터 6.2까지 checkWin 함수 생성 후 호출
		// 6.1. 가로/세로 돌 체크하기
		
		if (checkWin(currentUser, board)==true){
			isWin=true;
		}
	
		// 6.2. 대각선을 체크하기
		// TODO 1.3: numCell에 맞춘 대각선 빙고 체크 코드로 확장
		// HINT: for 문
		// 대각선 체크 (왼쪽 위 -> 오른쪽 아래)
        bool leftDiagWin = true;
        for (int i = 0; i < numCell; i++) {
            if (board[i][i] != currentUser) {
                leftDiagWin = false;
                break;
            }
        }
        // 대각선 체크 (오른쪽 위 -> 왼쪽 아래)
        bool rightDiagWin = true;
        for (int i = 0; i < numCell; i++) {
            if (board[i][numCell - 1 - i] != currentUser) {
                rightDiagWin = false;
                break;
            }
        }
        // 대각선 중 하나라도 완성되었을 경우 승리
        if (leftDiagWin || rightDiagWin) {
			isWin = true;
		}

		// 승리자가 결정되었으면 해당 플레이어를 출력하고 게임을 종료한다.
		if (isWin == true) {
			cout << k % 3 + 1<< "번 유저(" << currentUser << ")의 승리입니다!" << endl;
			break;
		}

		// 7. 모든 칸 다 찼는지 체크하기
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		if (checked == 0) {
			cout << "모든 칸이 다 찼습니다. 종료합니다. " << endl;
			break;
		}
		k++;
	}

	return 0;
}