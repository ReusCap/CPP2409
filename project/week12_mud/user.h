#include <iostream>
using namespace std;

class User{
private:
	int hp;
	// 아이템 먹은 횟수 저장 변수
	int itemCnt;
public:
	User();
    void IncreaseHP(int inc_hp);
	void DecreaseHP(int dec_hp);
	void incItem();
	int GetHP();
	friend ostream& operator<<(ostream& os, const User& user){
    	os <<"현재 HP는 " << user.hp <<"이고, 먹은 아이템은 총 " << user.itemCnt << "개 입니다." << endl;
		return os;
	}
};