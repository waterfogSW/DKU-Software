#include<iostream>
#include<math.h>
using namespace std;

class point {
private:
    int x, y;
public:
    point(int _x, int _y);
    float two_distance(point a);
    friend float distance2(point a, point b);
};

point::point(int _x, int _y){
    x = _x;
    y = _y;
}

float point::two_distance(point a){
    return sqrt(pow((a.x-x),2) + pow((a.y-y),2));
}

float distance2(point a, point b){
    return sqrt(pow((a.x-b.x),2) + pow((a.y-b.y),2));
}

int main(){
    point p1(3,4), p2(-1,-5);
    cout << "p1과 p2 거리 = " << p1.two_distance(p2) << endl;
    cout << "p1과 p2 거리 = " << distance2(p1,p2) << endl;
}