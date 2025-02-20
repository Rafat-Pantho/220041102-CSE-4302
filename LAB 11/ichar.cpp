#include <iostream>
#include <fstream>

using namespace std;

int main(){
    char c;
    ifstream infile("Test - 1. TXT");
    while(infile){
        infile.get(c);
        cout<<c;
    }
    cout<<endl;
    return 0;
}