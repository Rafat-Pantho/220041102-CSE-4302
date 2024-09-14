#include <iostream>

using namespace std;

void func(int &r, char &s){
    r = 556;
    s = 'x';
}

int main(){
    int a = 10;
    char bb = 'c';

    func(a, bb);

    cout << a << ' ' << bb << endl;

    return 0;
}