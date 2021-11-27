#include<iostream>
#include<math.h>
using namespace std;

class point {
private:
    int x, y;
public:
    point(int _x, int _y);
    double origin_distance();
};

point::point(int _x, int _y){
    x = _x;
    y = _y;
}

double point::origin_distance(){
    return sqrt((x*x)+(y*y));
}

int main(){
    point p1(3, 4), p2(-1,-5);
    cout << "p1의 원점거리 =" << p1.origin_distance() << endl;
    cout << "p2의 원점거리 =" << p2.origin_distance() << endl;
}