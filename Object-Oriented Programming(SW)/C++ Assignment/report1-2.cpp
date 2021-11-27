#include<iostream>

using namespace std;

int main() {
    int primenum[1000];
    int idx=0;
    for (int i = 1000; i <= 2000; i++)
    {
        for (int j = 2; j < i; i++) //1과 자기자신 제외
        {
            if(i%j == 0) break;
            primenum[idx] = i;
            idx++;
        }
    }

    cout << "1000과 2000 사이의 소수: ";
    for (int i = 0; i < 1000; i++)
    {
        if(primenum[i]){
            cout << primenum[i] << " ";
        }
        else break;
    }
    
}