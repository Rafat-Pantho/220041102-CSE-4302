#include <iostream>

using namespace std;

inline int add(int a, int b){
    return a + b;
}
inline int add(int a, int b, int c){
    return a + b + c;
}

int main(){
    int a = 45, b = 56, c = 34;

    cout << add(a, b) << endl;
    cout << add(a, b, c) << endl;

    return 0;
}