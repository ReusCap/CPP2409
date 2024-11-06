#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
    vector<int> student;
    int input=0;
    int sum=0;
    int count =0;
    while(true){
        cout << "성적을 입력하시오(종료는 -1) : ";
        cin >> input;
        if (input!=-1){
            student.push_back(input);
            count+=1;
        }
        else{
            break;
        }
    }
    for (auto e:student){
        sum+=e;
    }
    cout << "성적 평균="<< sum/count << endl;;
    return 0;
}
