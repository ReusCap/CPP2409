#include <iostream>
using namespace std;

int main(){
    const int numCell =3;
    char board[numCell][numCell]{};
    int x,y; // 사용자에게 입력받는 행,열 좌표를 저장할 변수

    // 보드판 초기화
    for (x=0; x<numCell; x++){
        for (y=0; y<numCell; y++){
            board[x][y]= ' ';
        }
    }
    // 게임하는 코드
    int k = 0;  // 차례 변수
    char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 문자변수
    while(true){
        // 1. 누구 차례인지 출력
        switch(k%2){
        case 0:
            cout << "첫번째 유저(X)의 차례입니다 -> ";
            currentUser = 'X';
            break;
        case 1:
            cout << "두번째 유저(O)의 차례입니다 -> ";
            currentUser = 'O';
            break;
        }
        // 2. 좌표 입력 받기
        cout <<"(행,열) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 3. 입력받은 좌표의 유효성 체크
        if (x>=numCell || y>= numCell){
            cout << x << ", " << y << ":";
            cout << " x와 y 둘 중 하나가 칸을 벗어납니다."<< endl;
            continue;
        }
        if (board[x][y] != ' '){
            cout << x << ", " << y << ": 이미 돌이 차있습니다."<< endl;
            continue;
        }
        // 4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드 판 출력
        for(int i = 0; i< numCell; i++){
            cout << "---|---|---" << endl;
            for (int j = 0; j< numCell; j++){
                cout << board[i][j];
                if (j == numCell-1){    // 판의 제일 오른쪽에는 "  |"가 없어서 2가 만나면 탈출
                    break;
                }
                cout << "  |";
            }
            cout << endl;
        }
        cout <<"---|---|---" << endl;

        // 6-1. 빙고 시 승자 출력 후 종료(가로,세로)
        
        bool flag = false; // 승자 확인 변수
        for (int i = 0; i < numCell; i++) {
            if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
                flag = true;
            }
            if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
                flag = true;
            }
        }

        // 6-2. 빙고 시 승자 출력 후 종료(대각선)
        if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
            flag = true;
        }
        if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
            flag = true;
        }

        // 6-3. 빙고 시 승자 출력 후 종료(승자 출력 후 종료)
        if (flag) {
            cout << currentUser << "가 승리했습니다!" << endl;
            break;
        }

        // 7. 모든 칸이 찼으면 종료(무승부)
        if (k==8){
            cout<< "무승부입니다.";
            break;
        }

        k++;
    }
    return 0;
}
