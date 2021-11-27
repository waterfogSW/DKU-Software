#include<iostream>
#include<cmath>

using namespace std;

struct point{
    int x, y;
};

int main(){
    point arr[5];

    cout << "좌표입력" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << ">>";
        cin >> arr[i].x >> arr[i].y;
    }

    double min = pow(float(arr[0].x),2) + pow(float(arr[0].y),2);
    int a = arr[0].x;
    int b = arr[0].y;

    for (int i = 1; i < 5; i++)
    {
        if(min > pow(float(arr[i].x),2) + pow(float(arr[i].y),2)){
            min = pow(float(arr[i].x),2) + pow(float(arr[i].y),2);
            a = arr[i].x;
            b = arr[i].y;
        }
    }

    cout << "결과:" << a << " " << b << endl;
}