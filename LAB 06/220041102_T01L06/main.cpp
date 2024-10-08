#include <iostream>
#include "counter.h"
using namespace std;

int main(){
    Counter c1(2,3),c2,c3;
    cout<<c1.getCount()<<endl;
    c1++;
    cout<<c1.getCount()<<endl;
    c2=c1++;
    cout<<c2.getCount()<<" "<<c1.getCount()<<endl;
    c3=++c1;
    cout<<c3.getCount()<<" "<<c1.getCount()<<endl;
    c1+=c2;
    cout<<c1.getCount()<<endl;
    c1= c2+c3;
    cout<<c1.getCount()<<endl;
}