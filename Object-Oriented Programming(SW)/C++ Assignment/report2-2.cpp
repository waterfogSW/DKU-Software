#include<iostream>
#include<cstring>
using namespace std;

void rev_str(char* _str1);
void rev_str(char* _str1, char* _str2);

int main(){
    char s1[80], s2[80];

    strcpy(s1,"hello");

    rev_str(s1,s2);
    rev_str(s1);

    cout << "s1: "<< s1 << endl <<"s2: " << s2 << endl;
}

void rev_str(char* _str1){
    char temp[80];
    for (int i = 0; i < strlen(_str1)/2; i++)
    {
        temp[i] = _str1[i];
        _str1[i] = _str1[strlen(_str1) - 1 - i];
        _str1[strlen(_str1) - 1 - i] = temp[i];
    }
}

void rev_str(char* _str1, char* _str2){
    for (int i = 0; i < strlen(_str1); i++)
    {
        _str2[i] = _str1[strlen(_str1) - 1 - i];
    }
}
