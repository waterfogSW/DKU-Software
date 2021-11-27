#include<iostream>
using namespace std;

class box{
private:
    double x, y, z; // 가로, 세로, 높이를 저장
    double volume; // 부피
public:
    void setbox(double a, double b, double c);
    void calcvolume();
    int vol();
};

void box::setbox(double a, double b,double c){
    x = a;
    y = b;
    z = c;
}

void box::calcvolume(){
    volume = x*y*z;
}

int box::vol(){
    return volume;
}

int main(){
    box mybox;
    int a,b,c;

    cin >> a >> b >> c;

    mybox.setbox(a,b,c);
    mybox.calcvolume();
    cout << mybox.vol();

}