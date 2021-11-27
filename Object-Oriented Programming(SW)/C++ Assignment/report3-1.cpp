#include<iostream>
using namespace std;

class coord{
private:
    int x,y;
public:
    coord(){x=0; y=0;}
    coord(int i, int j){x=i; y=j;}
    void get_xy(int &i, int &j){i=x; j=y;}
    coord operator*(coord op2);
    coord operator/(coord op2);
};

coord coord::operator*(coord op2){ // *연산자 중복
    coord temp;
    temp = *this;
    temp.x *= op2.x;
    temp.y *= op2.y;
    return temp;
}

coord coord::operator/(coord op2){ // /연산자 중복
    coord temp;
    temp = *this;
    temp.x /= op2.x;
    temp.y /= op2.y;
    return temp;
}

int main(){
    int i,j;
    coord c1(6,7), c2(2,5), c3;
    c3 = c1 * c2;
    c3.get_xy(i,j);
    cout << i << " " << j << endl;
    c3 = c1 / c2;
    c3.get_xy(i,j);
    cout << i << " " << j << endl;
}