#include<iostream>
using namespace std;

int main(){
    int n;
    int *arr;
    cout << "베열의 크기:";
    cin >> n;
    arr = new int [n];
    cout << n << "개의 수:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < 5; j++)
        {
            if(arr[i] > arr[j]){
                count++;
            }
        }
        cout << arr[i] << "->" << count << "\n";
        
    }
    return 0;
}
