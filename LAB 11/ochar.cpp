#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    string s = "Time is a great teacher, but unfortunately "" it kills all its pupils. Berlioz";
    ofstream outfile("Test - 1. TXT");
    for (int j=0;s[j]!='\0';j++)outfile.put(s[j]);
    cout <<"File written\n";
    return 0;
}