#include <iostream>
using namespace std;

const int numCell = 3;
char board[numCell][numCell]{};

// isFull 함수 수정: numCell 파라미터 제거
int isFull(char board[numCell][numCell]) {
    int full = 0;
    for (int i = 0; i < numCell; i++) {
        for (int j = 0; j < numCell; j++) {
            if (board[i][j] == ' ') {
                full++;  // 빈 칸 개수 증가
            }
        }
    }
    return full;  // 남은 빈 칸 개수 반환
}

int main() {
    int x, y;  // 사용자에게 입력받는 행, 열 좌표
    int k = 0;  // 차례 변수
    char currentUser = 'X';  // 현재 유저의 돌

    // 보드 초기화
    for (x = 0; x < numCell; x++) {
        for (y = 0; y < numCell; y++) {
            board[x][y] = ' ';
        }
    }

    while (true) {
        // 차례 출력
        cout << (k % 2 == 0 ? "첫번째 유저(X)" : "두번째 유저(O)") << "의 차례입니다 -> ";
        currentUser = (k % 2 == 0) ? 'X' : 'O';

        // 좌표 입력 받기
        cout << "(행,열) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 유효성 검사
        if (x < 0 || y < 0 || x >= numCell || y >= numCell) {
            cout << "유효하지 않은 좌표입니다. 다시 입력하세요." << endl;
            continue;
        }
        if (board[x][y] != ' ') {
            cout << "이미 돌이 있는 자리입니다. 다시 입력하세요." << endl;
            continue;
        }

        // 돌 놓기
        board[x][y] = currentUser;

        // 보드 출력
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                cout << board[i][j];
                if (j < numCell - 1) cout << " | ";
            }
            cout << endl;
            if (i < numCell - 1) cout << "---|---|---" << endl;
        }

        // 승자 체크
        bool flag = false;
        for (int i = 0; i < numCell; i++) {
            if ((board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) ||
                (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser)) {
                flag = true;
                break;
            }
        }
        if ((board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) ||
            (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser)) {
            flag = true;
        }

        if (flag) {
            cout << currentUser << "가 승리했습니다!" << endl;
            break;
        }

        // 무승부 체크
        int checked = isFull(board);
        if (checked == 0) {  // 빈 칸이 없으면 무승부
            cout << "모든 칸이 다 찼습니다. 무승부입니다." << endl;
            break;
        }

        k++;  // 차례 변경
    }
    return 0;
}
