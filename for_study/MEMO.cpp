// 1. 상수 표현
// #define 상수이름 숫자 형태로 ;안넣음 
#define pi 3.141592
// const 자료형 상수이름=값; 형태 ;넣음
const int age = 24;

/* week2
1. 여기서는 참, 거짓 소문자 true, false로 한다.
2. 또한 char 자료형은 '' 1개의 일반따옴표 사용.
3. 문자열 쓰려면 #include <string>하고 string 자료형으로 변수선언
4. to_string(숫자형 데이터)는 그냥 숫자 문자열로 바꿔줌
 
5. auto 키워드 : 자료형처럼 쓰이며 컴파일러가 자동으로 추론
    그런데 함수의 매개변수로는 auto 쓰면 안된다.
6. sizeof(변수명, 자료형) 크기 반환
7. 실수는 double 쓰렴
*/
/* week4
1. 보통 c++이 bool값 출력할때는 true를 1 출력 false를 0으로 출력 
2. 논리표현식은 &&와 ||처럼 2개씩 씀.
3. NOT은 !x처럼 !만 써서 반대로 만듦
4. 1&&2는 true&&true니까 1출력
5. if else문은 if(){}형태. elif는 else if(){}로 쓴다.
6. if(char x < 'h') 이런식으로 아스키코드 비교도 가능
7. cin a >> b >> c; 처럼 공백, 엔터, 탭키를 기준우로 구분해서 입력
8. switch문은 switch(choice){ case 1: case 2: } break문 default에는 필요x
    case뒤에 중괄호 없어도 그냥 다 잘 작동

9. for(int i=0; i<10; i++){}
10. while(i<=9){}
11. do{ }while(조건식); 형태이다. while뒤에 ;세미콜론 붙여
12. getline(cin, str1); 은 str1변수에 공백 포함한 한 줄 입력받음. ex) hello world도 한번에 입력. 
13. break나 continue사용
14. case1: case2: case3:
        VOWEL++
        break;
    가능
15. #include <time.h> 하고 rand()는 난수 생성
16. rand() %100 은 난수를 100으로 나눈 나머지니까 0-99출력
17. 형변환 (int)str[0] 같은걸로 char형을 int형으로 바꿀 수 있다.
    그런데 여기서 string은 안되고 int, double, char, float등만 가능
    아스키 코드로 변환할때도 자주 사용한다.
*/

/*
1. 배열 초기화때 인덱스가 변수는 X 상수여야한다.
const int num = 5;
int num_arr[num];
    C++의 배열 선언은 int num[5]={1,2,3,4,5}이런식으로 중괄호 형태임.
2. char num[5] 처럼 char형도 가능
3. 배열은 선언만 한 경우 쓰레기값이 들어있다.
4. 일부만 초기화한 경우 나머지는 0으로 채워짐
    char형은 \0 곧 null이 채워짐
    string형은 "" 들어감.
5. 범위기반 for문 for i in list[]처럼
    for (int i : list){} ** 물론 list배열의 자료형도 int여야함.
6. switch-case 블록에서 변수선언 불가
    하고 싶으면 case 1:{}로 중괄호 만들고 안에서 선언은 가능
7. 2차원 배열 생성
    int numbers[줄수][칸수] = {{1, 2, 3, 4,{6, 7, 8, 9, 0},{2, 4, 6, 8, 0}};
8. tic_tec_toe한번 유심히 다시 살펴봐 교수님 정답이랑도 비교
*/

/* 6주차
1. 함수정의
    int sum(int x, int y){
        int result=x+y;
        return result;}
2. 매개변수 순서와 개수 맞춰
3. 매개변수 없으면 ()안을 비우던가 (void)
4. 반환값 없으면 void sum()
5. return으로 함수 종료 가능.
6. 함수 원형 선언
int sum(int x, int y); 이거를 main함수 위에만 적어놔.
7. 전역변수 : main이든 다른 함수든 그냥 밖에 적혀있는 변수
8. 지역변수 : main이나 다른 함수 안에서 정의된 변수
9. extern int num; 같이 extern키워드 붙이면 전역변수 됨

10. 헤더파일
myheader.h에는 그냥 int sum() 원형선언
myheader.cpp에는 그냥 #include <iostream>이랑 <myheader.h>하고
    int sum()함수 작성
그러면 hello.cpp에서 #include <myheader.h>하면 sum함수 사용가능
*/ 

/* 7주차
1. 매개변수는 미리 초기화 가능
    int sum(int x, int y=0)
    만약 sum(1)하면 1+0하는거임

2. 참조자 : 기존 함수에 대한 별명 만들기
    int num=42;
    int &ref = num;
    이러면 ref도 num과 똑같은거 취급
    ref = 100하면 
    num도 100이 됨.
3. 참조자 기반 매개변수 쓰면 함수에서도 
    void modify(int &x, int &y){
        x=x+2
        y=y+2}
    리턴값 없이도 실제 값 변경 가능
4. 중복함수 : 매개변수에 따라 다른 함수 사용되는거 
    1) 이름은 같지만 매개변수와 반환값 다르게
    int sum()
    double sum()처럼
    2) 매개변수 개수 다르게
    int sum(int x, int y)
    int sum(int x, int y, int z)
5. 클래스 함수와 객체 함수는 따로 있다.
    tolower(str) 같은건 전역 함수(헤더)
    str.empty() 같은건 클래스 객체 맴버 함수(객체)
6. 문자열 객체
    1) 문자열은 char 배열과 동일.
    char alphbet[]="text";  
    이러면 t e x t \0 이렇게 5자리 생김
    2) 문자열 객체
    string s1 = "hello"
    s1 + s2나 s1 > s2 비교 가능
7. tolower()같은건 char대상이다. 
    for (char &c : str){
        c=tolower(c);
    }
    이거 쓸때 &c로 str의 각 실제 자리값들을 가져와서 
    소문자화 시키는거임.
8. s.empty() : s비어있으면 true반환
9. s.insert(index, s2) s의 index위치에 s2 삽입
10. s.find(s2) : s2 찾은 인덱스 반환
11. s.find(s2, index) : index위치부터 검색시작 s2 발견되는 첫 인덱스 반환
12. s.length() : s길이 구하기
13. s.erase(index, len)
14. 해밍거리

*/


