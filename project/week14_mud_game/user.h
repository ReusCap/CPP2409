#include <iostream>
using namespace std;

// User 클래스는 순수 가상 함수로 구성된 인터페이스
class User {
public:
    virtual void IncreaseHP(int inc_hp) = 0;
    virtual void DecreaseHP(int dec_hp) = 0;
    virtual void IncItem() = 0;
    virtual int GetHP()= 0;
    virtual void DoAttack() = 0;
    virtual ~User() {}  
    friend ostream& operator<<(ostream& os, const User& user) {
        return user.Print(os);
    }

protected:
    virtual ostream& Print(ostream& os) const = 0;
};


// Magician 클래스 선언 (구현은 user.cpp에서)
class Magician : public User {
private:
    int hp;
    int itemCnt;
public:
    Magician();
    void IncreaseHP(int inc_hp) override;
    void DecreaseHP(int dec_hp) override;
    void IncItem() override;
    int GetHP() override;
    void DoAttack() override;
    ostream& Print(ostream& os) const override;
};

// Warrior 클래스 선언 (구현은 user.cpp에서)
class Warrior : public User {
private:
    int hp;
    int itemCnt;
public:
    Warrior();
    void IncreaseHP(int inc_hp) override;
    void DecreaseHP(int dec_hp) override;
    void IncItem() override;
    int GetHP() override;
    void DoAttack() override;
    ostream& Print(ostream& os) const override;
};
