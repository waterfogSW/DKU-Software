#include<iostream>
using namespace std;

int powerx(int x);
int powerx(int x,int y);
int powerx(int x, int y, int z);

int main(){
    cout << powerx(2) << "\n";
    cout << powerx(2,3) << "\n";
    cout << powerx(2,3,4) << "\n";

}

int powerx(int x){
    return x*x;
}

int powerx(int x, int y){
    int temp = x;
    for (int i = 0; i < y-1; i++)
    {
        x *= temp;
    }
    return x;
}

int powerx(int x,int y, int z){
    int temp = x;
    for (int i = 0; i < y-1; i++)
    {
        x *= temp;
    }
    return x*z;
}