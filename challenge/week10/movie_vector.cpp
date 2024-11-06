#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Movie{
public:
    string title;
    double score;
    Movie(){title=""; score=0;}
    Movie(string title, double score){
        this->title=title;
        this->score=score;
    }
    void Print(){
        cout <<title << ": "<< score << endl;
    }
};

int main(void){
    vector<Movie> objArray;
    Movie obj1{"titinic", 9.9};
    objArray.push_back(obj1);

    Movie obj2{"gone with the wind",9.6};
    objArray.push_back(obj2);

    Movie obj3{"terminator",9.7};
    objArray.push_back(obj3);
    
    for (Movie c : objArray)
        c.Print();

    return 0;
}
