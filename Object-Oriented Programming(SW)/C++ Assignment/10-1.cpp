#include<iostream>
#include<cstdlib>
using namespace std;

class rectangle{
private:
    int x1, y1;
    int x2, y2;
public:
    rectangle(int _x1,int _y1, int _x2, int _y2);
    int area();
    int largearea(rectangle rect);
};

rectangle::rectangle(int _x1,int _y1, int _x2, int _y2){
    x1 = _x1;
    y1 = _y1;
    x2 = _x2;
    y2 = _y2;
}

int rectangle::area(){
    return (abs(x2 - x1)) * (abs(y2 - y1));
}

int rectangle::largearea(rectangle rec){
    if(rec.area()> area()){
        return rec.area();
    }
    else
    {
        return area();
    }
}

int main(){
    rectangle r1(1,1,3,4), r2(-1,-2,1,-5);
    cout << "사각형 1의 면적 = " << r1.area() << endl;
    cout << "더큰 사각형의 면적 = " << r1.largearea(r2) << endl;
}