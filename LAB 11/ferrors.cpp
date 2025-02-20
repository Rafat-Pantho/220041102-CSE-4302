#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream file;
    file.open("test-1.dat");
    if(!file) cout<<"\nError opening file GROUP.DAT\n";
    else cout<<"\nFile opened successfully\n";
    //cout<< "\nFile = "<<file;
    cout<< "\nError state = " <<file.rdstate();
    cout<< "\ngood() = " <<file.good();
    cout<< "\neof() = " <<file.eof();
    cout<< "\nbad() = " <<file.bad();
    cout<< "\nfail() = " <<file.fail();
    file.close();
    return 0;
}