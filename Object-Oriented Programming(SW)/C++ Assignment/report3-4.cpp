#include<iostream>
using namespace std;

class coord{
private:
    int x, y;
public:
    coord(){x=0; y=0;}
    coord(int i, int j){x = i; y = j;}
    void get_xy(int &i, int &j){i = x; j = y;}
    friend coord operator-(coord &op1, coord &op2);
    friend coord operator/(coord &op1, coord &op2);
};

coord operator-(coord &op1, coord &op2){
    coord temp;
    temp.x = op1.x - op2.x;
    temp.y = op1.y - op2.y;
    return temp;
}

coord operator/(coord &op1, coord &op2){
    coord temp;
    temp.x = op1.x / op2.x;
    temp.y = op1.y / op2.y;
    return temp;
}

int main(){
    int i, j;

    coord c1(10,7), c2(2,3), c3;
    c3 = c1 - c2;
    c3.get_xy(i, j);
    cout << i << "," << j << '\n';
    c3 = c1 / c2;
    c3.get_xy(i, j);
    cout << i << "," << j << '\n';
}