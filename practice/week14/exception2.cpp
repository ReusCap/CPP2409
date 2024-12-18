#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
using namespace std;

int main(){
    int pizza_slices =0;
    int persons=-1;
    int slices_per_person =0;

    try
    {
        cout <<"피자 조각 수를 입력하시오: ";
        cin >> pizza_slices;
        if (pizza_slices==0)
            throw invalid_argument("0은 나눌 수 없습니다.");
        cout <<"사람 수를 입력하시오: ";
        cin >> persons;
        if (persons==0)
            throw persons;
        slices_per_person = pizza_slices /persons;
        cout << "한 사람 당 피자는 "<< slices_per_person <<"입니다."<<endl;
    }
    // persons가 int타입이라 int e받는다.
    catch(exception& e)
    {
        cerr <<"에러: " << e.what() << endl;
    }
    catch(...)
    {
        cerr <<"에러" << endl;
    }
    
    return 0;
}