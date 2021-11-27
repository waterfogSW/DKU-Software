#include<iostream>

using namespace std;

class mystring{
private:
    char str[80];
public:
    mystring(char *s);
    int strlength();
    int numchar(char ch);
};

mystring::mystring(char *s){
    for (int i = 0; i<80; i++)
    {
        str[i] = s[i];
    }
}

int mystring::strlength(){
    int length = 0;
    for (int i = 0; i < 80; i++)
    {
        if(str[i] == '\0'){
            break;
        }
        length++;
    }
    return length;
}

int mystring::numchar(char ch){
    int count = 0;
    for (int i = 0; i < 80; i++)
    {
        if (str[i] == ch)
        {
            count++;
        }
        else if(str[i] == '\0'){
            break;
        }
    }
    return count;
}

int main(){
    mystring my("I am studing C++ language");
    cout << "문자열 길이 : " << my.strlength() << endl;
    cout << "문자 a 의 개수 : " << my.numchar('a') << endl;
}