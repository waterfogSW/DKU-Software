#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    char text[100];
    int numeng = 0; // 영문자 개수
    int numpunc = 0; // 구두점 개수
    int numnum = 0; // 숫자 개수

    cout << "입력: ";
    gets_s(text);

    for (int i = 0; i < 100; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122)) {
            numeng++;
        }
        else if (text[i] >= 48 && text[i] <= 57) {
            numnum++;
        }
        else if (text[i] == '!' || text[i] == '.' || text[i] == ',') {
            numpunc++;
        }
    }

    cout << "영문자 개수:" << numeng << "\n";
    cout << "숫자 개수:" << numnum << "\n";
    cout << "구두점 개수:" << numpunc << "\n";

}