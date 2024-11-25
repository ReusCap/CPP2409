#include "user.h"

// Magician 구현
Magician::Magician() : hp(20), itemCnt(0) {}
void Magician::IncreaseHP(int inc_hp) { hp += inc_hp; }
void Magician::DecreaseHP(int dec_hp) { hp -= dec_hp; }
void Magician::IncItem() { itemCnt += 1; }
int Magician::GetHP() { return hp; }
void Magician::DoAttack() { cout << "마법 사용" << endl; }
ostream& Magician::Print(ostream& os) const {
    os << "Magician의 현재 HP는 " << hp << "이고, 먹은 아이템은 총 " << itemCnt << "개 입니다.";
    return os;
}

// Warrior 구현
Warrior::Warrior() : hp(20), itemCnt(0) {}
void Warrior::IncreaseHP(int inc_hp) { hp += inc_hp; }
void Warrior::DecreaseHP(int dec_hp) { hp -= dec_hp; }
void Warrior::IncItem() { itemCnt += 1; }
int Warrior::GetHP() { return hp; }
void Warrior::DoAttack() { cout << "베기 사용" << endl; }
ostream& Warrior::Print(ostream& os) const {
    os << "Warrior의 현재 HP는 " << hp << "이고, 먹은 아이템은 총 " << itemCnt << "개 입니다.";
    return os;
}
