#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    char text[100][80];
    for (int i = 0; i < 100; i++)
    {
        cout << i << ": ";
        gets_s(text[i]);
        if(text[i][0]) break;
    }

    int numblk = 0; // 공백 수
    int numcom = 0; // 콤마 수
    int numperiod = 0; // 마침표 수

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 80; j++)
        {
            switch (text[i][j])
            {
            case ' ':
                numblk++;
                break;
            case ',':
                numcom++;
                break;
            case '.':
                numperiod++;
                break;
            default:
                break;
            }
        }
        
    }

    cout << "공백의 수: " << numblk << "\n";
    cout << "콤마의 수: " << numcom << "\n";
    cout << "마침표의 수: " << numperiod << "\n";
    
}