#include<iostream>

using namespace std;

float avg(float arr[], int n);

int main(){
    int size;
    float num[100];
    cout << "입력 크기: ";
    cin >> size;

    cout << "배열 입력" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << ">>";
        cin >> num[i];
    }

    cout << "평균: " << avg(num,size);
}

float avg(float arr[], int n){
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum+= arr[i];
    }

    return sum / float(n);
}