#include <iostream>
#include <string>
#include "user.h"
#include <vector>
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(const vector<vector<int>>& map, int mag_x, int mag_y, int war_x, int war_y);
bool checkGoal(const vector<vector<int>>& map, int user_x, int user_y);
// HP 0인지 확인 함수, HP출력 함수, HP변화 함수, 아이템/적/포션 메시지 출력 함수
bool CheckUser(User user);
void HP_print(User user);
int HP_change(User &user, const vector<vector<int>>& map, int user_x, int user_y);
void checkState (const vector<vector<int>>& map, int user_x , int user_y );
// 아이템 칸 가면 아이템 줍는 함수
void get_item(User &user, const vector<vector<int>> &map, int user_x, int user_y);

// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	vector<vector<int>> map{ {0, 1, 2, 0, 4},
							{1, 0, 0, 2, 0},
							{0, 0, 0, 0, 0},
							{0, 2, 3, 0, 0},
							{3, 0, 0, 0, 2} };
	// 단일 객체 생성
    Magician magician;
	Warrior warrior;

	// 유저의 위치를 저장할 변수
	magician.user_x = 0; // 가로 번호
	magician.user_y = 0; // 세로 번호
	warrior.user_x = 0; // 가로 번호
	warrior.user_y = 0; // 세로 번호
	bool isMagicianTurn = true; // Magician 차례인지 여부를 나타내는 플래그

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프
		// 사용자의 입력을 저장할 변수
		string user_input = "";

		// 현재 차례인 유저를 선택
		// currentUser을 User타입의 참조변수로 설정하고, static_cast로 magician과 warrior을 User타입으로 변환
        User& currentuser = isMagicianTurn ? static_cast<User&>(magician) : static_cast<User&>(warrior);

		// 차례 출력 
        cout << (isMagicianTurn ? "첫번째 유저(Magician)의 차례입니다." : "두번째 유저(Warrior)의 차례입니다.") << endl;

		// HP 출력 함수
		HP_print(currentuser);
		cout << "명령어를 입력하세요 (up, down, left, right, map, quit, info): ";
		cin >> user_input;

		if (user_input == "up") {
			// 위로 한 칸 올라가기
			currentuser.user_y -= 1;
			bool inMap = checkXY(currentuser.user_x, mapX, currentuser.user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				currentuser.user_y += 1;
			}
			else {
				cout << "위로 한 칸 올라갑니다." << endl;
				displayMap(map, magician.user_x, magician.user_y, warrior.user_x, warrior.user_y);
				// 위로 이동시 HP 변화 함수
				HP_change(currentuser, map, currentuser.user_x, currentuser.user_y);
				// 아이템, 적, 포션 만났을 때 메시지 출력 함수
				checkState (map, currentuser.user_x , currentuser.user_y );
				get_item(currentuser, map, currentuser.user_x, currentuser.user_y);
			}
		}
		else if (user_input == "down") {
			// TODO: 아래로 한 칸 내려가기
			currentuser.user_y += 1;
			bool inMap = checkXY(currentuser.user_x, mapX, currentuser.user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				currentuser.user_y -= 1;
			}
			else {
				cout << "아래로 한 칸 내려갑니다." << endl;
				displayMap(map, magician.user_x, magician.user_y, warrior.user_x, warrior.user_y);
				// 아래로 이동시 HP 변화 함수
			    HP_change(currentuser, map, currentuser.user_x, currentuser.user_y);
				// 아이템, 적, 포션 만났을 때 메시지 출력 함수
				checkState (map, currentuser.user_x , currentuser.user_y );
				get_item(currentuser, map, currentuser.user_x, currentuser.user_y);
			}
		}
		else if (user_input == "left") {
			// TODO: 왼쪽으로 이동하기
			currentuser.user_x -= 1;
			bool inMap = checkXY(currentuser.user_x, mapX, currentuser.user_y, mapY);

			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				currentuser.user_x += 1;
			}
			else {
				cout << "왼쪽으로 이동합니다." << endl;
				displayMap(map, magician.user_x, magician.user_y, warrior.user_x, warrior.user_y);
				// 왼쪽으로 이동시 HP 변화 함수
				HP_change(currentuser, map, currentuser.user_x, currentuser.user_y);
				// 아이템, 적, 포션 만났을 때 메시지 출력 함수
				checkState (map, currentuser.user_x , currentuser.user_y );
				get_item(currentuser, map, currentuser.user_x, currentuser.user_y);
			}
		}
		else if (user_input == "right") {
			// TODO: 오른쪽으로 이동하기
			currentuser.user_x += 1;
			bool inMap = checkXY(currentuser.user_x, mapX, currentuser.user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				currentuser.user_x -= 1;
			}
			else {
				cout << "오른쪽으로 이동합니다." << endl;
				displayMap(map, magician.user_x, magician.user_y, warrior.user_x, warrior.user_y);
				// 오른쪽로 이동시 HP 변화 함수
				HP_change(currentuser, map, currentuser.user_x, currentuser.user_y);
				// 아이템, 적, 포션 만났을 때 메시지 출력 함수
				checkState (map, currentuser.user_x , currentuser.user_y );
				get_item(currentuser, map, currentuser.user_x, currentuser.user_y);
			}
		}
		else if (user_input == "map") {
			// TODO: 지도 보여주기 함수 호출
			displayMap(map, magician.user_x, magician.user_y, warrior.user_x, warrior.user_y);
			// 턴이 안바뀌도록
			continue;
		}
		else if (user_input == "quit") {
			cout << "종료합니다.";
			break;
		}
		else if (user_input == "info") {
			cout << currentuser << endl;
			// 턴이 안바뀌도록
			continue;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, currentuser.user_x, currentuser.user_y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

		// HP가 0 이하가 되었을때 확인
        // CheckUser()함수로
		if (CheckUser(currentuser)==false){
			break;
		}
		isMagicianTurn = !isMagicianTurn;
	}
	return 0;
}

// hp가 0인지 체크하는 함수
bool CheckUser(User user){
    if (user.GetHP()<=0){
        cout << "HP가 0 이하가 되었습니다. 실패했습니다."<< endl;
        return false;
    }
    else{
        return true;
    }
}

// 체력 출력 함수
// 그냥 단순하게 현재 HP출력시켜주는 함수
void HP_print(User user){
	cout << "현재 HP: "<< user.GetHP() << "  ";
}

// 체력 변화 함수
// 좌표값에 따라 switch문으로 case별로 체력떨어트리고 HP값을 return한다.
// 여기서 IncreaseHP, DecreaseHP 멤버 함수 사용
// 여기서는 hp값을 변경하니까 객체의 참조자가 매개변수로 전달되어야 한다.
int HP_change(User &user, const vector<vector<int>> &map, int user_x, int user_y){
	int posState = map[user_y][user_x];
	switch (posState){
		case 0:
			user.DecreaseHP(1);
			break;
		case 1:
			user.DecreaseHP(1);
			break;
		case 2:
			user.DecreaseHP(3);
			break;
		case 3:
			user.IncreaseHP(1);
			break;
		case 4:
			user.DecreaseHP(1);
			break;
		}
	return user.GetHP();
}

// 아이템, 적, 포션 만났을 때 메시지 출력 함수
void checkState (const vector<vector<int>> &map, int user_x , int user_y ){
	int posState = map[user_y][user_x];
	switch (posState){
		case 0:
			break;
		case 1:
			cout << "아이템이 있습니다." << endl;
			break;
		case 2:
			cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
			break;
		case 3:
			cout << "포션이 있습니다. HP가 2 늘어납니다." << endl;
			break;
		case 4:
			break;
		}
}
// 아이템 만나면 아이템 줍고 줍는 함수.
void get_item(User &user, const vector<vector<int>> &map, int user_x, int user_y){
	int posState = map[user_y][user_x];
	switch (posState){
		case 0:
			break;
		case 1:
			user.IncItem();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		}
}

// 지도와 사용자 위치 출력하는 함수
// 매개변수에 mag_x,y와 war_x,y추가
void displayMap(const vector<vector<int>>& map, int mag_x, int mag_y, int war_x, int war_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == mag_y && j == mag_x && i == war_y && j == war_x) {
                cout << "MAG, WAR|"; // 두 유저가 같은 위치에 있을 때
            } else if (i == mag_y && j == mag_x) {
                cout << "   MAG  |"; // Magician의 위치
            } else if (i == war_y && j == war_x) {
                cout << "   WAR  |"; // Warrior의 위치
            } else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "        |"; // 6칸 공백
					break;
				case 1:
					cout << " 아이템 |";
					break;
				case 2:
					cout << "   적   |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << "  포션  |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << " 목적지 |";
					break;
				}
			}
		}
		cout << endl;
		cout << "---------------------------------------------" << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(const vector<vector<int>> &map, int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}
