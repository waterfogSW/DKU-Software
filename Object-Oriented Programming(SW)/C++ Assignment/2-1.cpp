#include<iostream>

using namespace std;

bool isPrimenum(int n);

int main(){
    int n;
    cout << "정수 n 입력 : ";
    cin >> n;
    if(isPrimenum(n)==true){
        cout << "소수입니다";
    }
    else{
        cout << "소수가 아닙니다";
    }
}

bool isPrimenum(int n){
    for (int i = 2; i < n; i++)
    {
        if(n%i == 0){
            return false;
        }
    }
    return true;
}