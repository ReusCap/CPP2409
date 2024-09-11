#include <iostream>
#include <string>

using namespace std;

int main(){
    int Fahrenheit;
    double Celsius;
    
    cout << "화씨온도: ";
    cin >> Fahrenheit;
    Celsius = (5.0/9.0)*(Fahrenheit-32);
    cout << "섭씨온도: "<< Celsius << endl;

    return 0;
}