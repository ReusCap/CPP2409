#include <iostream>
#include <string> // string 사용을 위해 추가
using namespace std;

// Person 클래스 정의
class Person {
private:
    string name; // 기본적으로 private

protected:
    string address; // protected로 설정

public:
    void SetName(string name) {
        this->name = name; // this->를 사용하여 클래스 멤버에 접근
    }
};

// Student 클래스 정의
class Student : public Person { // Person 클래스를 상속
public:
    // 주소 설정 메서드
    void SetAddress(string add) {
        address = add; // protected 멤버에 접근 가능
    }
    // 주소 반환 메서드
    string GetAddress() {
        return address;
    }
};

int main() {
    Student obj;
    obj.SetName("미수");
    obj.SetAddress("서울시 종로구 1번지");
    cout << obj.GetAddress() << endl;

    return 0;
}
