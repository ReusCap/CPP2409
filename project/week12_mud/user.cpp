#include "user.h"

User::User(){
    hp=20;
    itemCnt=0;
}
void User::IncreaseHP(int inc_hp){
    hp+=inc_hp;
}
void User::DecreaseHP(int dec_hp){
    hp-=dec_hp;
}
void User::incItem(){
    itemCnt+=1;
}
int User::GetHP(){
    return hp;
}