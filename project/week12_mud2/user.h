#include <iostream>
using namespace std;

class User{
private:
	int hp;
	// 아이템 먹은 횟수 저장 변수
	int itemCnt;
public:
	// user_x와 user_y를 class의 public안에 넣는다.
	int user_x;
	int user_y;
	User();
    void IncreaseHP(int inc_hp);
	void DecreaseHP(int dec_hp);
	void IncItem();
	int GetHP();
	friend ostream& operator<<(ostream& os, const User& user){
    	os <<"현재 HP는 " << user.hp <<"이고, 먹은 아이템은 총 " << user.itemCnt << "개 입니다." << endl;
		return os;
	}
	void DoAttack();
};

class Magician: public User{
public:
	Magician(){}
	void DoAttack(){
		User::DoAttack();
		cout <<"마법 사용"<<endl;
	}
};

class Warrior: public User{
public:
	Warrior(){}
	void DoAttack(){
		User::DoAttack();
		cout <<"베기 사용"<<endl;
	}
};
