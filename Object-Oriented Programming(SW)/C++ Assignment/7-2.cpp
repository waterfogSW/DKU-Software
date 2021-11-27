#include<iostream>
using namespace std;

class queue{
private:
    int* q;
    int size;
    int sloc, rloc;
public:
    queue(int n);
    ~queue();
    void qput(int i);
    int qget();
    int max();
    void reverse_print(int num);
};

queue::queue(int n = 100){
    sloc = rloc = -1;
    size = n;
    q = new int[size];

    cout << "Queue initialized.\n";
}

queue::~queue(){
    cout << "Queue destroyed.\n";
}

void queue::qput(int i){
    if(sloc==(size-1)){
        cout << "Queue is full.\n";
        return;
    }
    sloc++;
    q[sloc] = i;
}

int queue::qget(){
    if(rloc == sloc){
        cout << "Queue Underflow.\n";
        return 0;
    }
    rloc++;
    return q[rloc];
}

int queue::max(){
    if(rloc == sloc){
        return -999;
    }
    int _max = 0;
    for (int i = rloc; i <= sloc; i++)
    {
        if (_max < q[i])
        {
            _max = q[i];
        }
    }
    return _max;
}

void queue::reverse_print(int num){
    if(rloc == sloc){
        cout << "Queue is empty";
        return;
    }
    int count = 0;
    for (int i = sloc; count < num; i--)
    {
        cout << q[i] << ' ';
        count++;
    }
    cout << endl;
}

int main(){
    queue a(20);
    cout << "6개의 값을 큐에 삽입할 것" << endl;
    for (int i = 0; i < 6; i++){
        int temp;
        cout << ">>";
        cin >> temp;
        a.qput(temp);
    }
    cout << a.max() << endl;
    a.reverse_print(4);
    
}