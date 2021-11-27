#include<iostream>
using namespace std;

int count_substr(char *sub,char *str);

int main(){
    char sub[] = "aba";
    char str[] = "aabababacabaabca";
    cout << "부분 문자열의 수: " << count_substr(sub, str) << "\n";
}

int count_substr(char *sub, char *str){
    int count = 0;
    char *p1,*p2;
    for (int i = 0; str[i]; i++)
    {
        p1 = &str[i];
        p2 = sub;
        while(*p2 && *p2 == *p1){
            p1++; p2++;
        }
        if(!*p2) count++;
    }
    return count;
}