#include<iostream>
using namespace std;

int main(){
    int a,b,c,d;
    char dummy;
    cout<<"Enter the 1st function "<<endl;
    cin>>a>>dummy>>b;
    cout << "Enter the 2nd function " << endl;
    cin >> c >> dummy >> d;
    cout<< a*d+b*c <<"/"<< b*d<<endl;
    return 0;
}