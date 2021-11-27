#include<iostream>
using namespace std;

class coord{
private:
    int x,y;
public:
    coord(){x=0; y=0;}
    coord(int i, int j){x=i; y=j;}
    void get_xy(int &i, int &j){i=x; j=y;}
    bool operator==(coord op2);
    bool operator&&(coord op2);
};

bool coord::operator==(coord op2){ // ==연산자 중복
    if((this->x == op2.x) && (this->y == op2.y)){
        return true;
    }
    else{
        return false;
    }
}

bool coord::operator&&(coord op2){ // &&연산자 중복
    if((this->x && op2.x) || (this->y && op2.y)){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int i,j;
    bool temp;
    coord c1(3,0), c2(5,0);
    temp = c1 == c2;
    cout << temp << '\n';
    temp = c1 && c2;
    cout << temp << '\n';
}