#include<iostream>

using namespace std;

int main(){
    int arr[5];
    cout << "입력 : ";
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i];
    }

    int min = arr[0];
    int idx = 0;

    for (int i = 1; i < 6; i++)
    {
        if(min > arr[i]){
            min = arr[i];
            idx = i;
        }
    }

    int temp;

    temp = arr[idx];
    arr[idx] = arr[0];
    arr[0] = temp; 

    cout<< "출력 : ";
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}