#include<iostream>
using namespace std;

class coord{
private:
    int x,y;
public:
    coord(){x=0; y=0;}
    coord(int i, int j){x=i; y=j;}
    void get_xy(int &i, int &j){i=x; j=y;}
    coord operator--();
    coord operator--(int notused);
};

coord coord::operator--(){ // -- 전위 연산자 중복
    x--;
    y--;
    return *this;
}

coord coord::operator--(int notused){ // -- 후위 연산자 중복
    coord temp = *this;
    x--;
    y--;
    return temp;
}

int main(){
    int i,j;
    bool temp;
    coord c1(3,0), c2;
    c2 = c1--;
    c2.get_xy(i,j);
    cout << i << " " << j << endl;
    c2 = --c1;
    c2.get_xy(i,j);
    cout << i << " " << j << endl;
}