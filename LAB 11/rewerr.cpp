#include <iostream>
#include <fstream>
#include <process.h>

using namespace std;

const int MAX = 1000;

int buff[MAX];

int main(){
    for(int j=0;j<MAX;)buff[j]=j++;
    ofstream os;
    os.open("edata-1.dat",ios::trunc|ios::binary);
    if(!os){
        cerr<<"Error opening file\n";
        exit(1);
    }
    cout << "Writing...\n";
    os.write(reinterpret_cast<char*>(buff),MAX*sizeof(int));
    if(!os){
        cerr <<"Error writing to file\n";
        exit(1);
    }
    os.close();
    for(int j=0;j<MAX;)buff[j++]==0;
    ifstream is;
    is.open("edata-1.dat",ios::binary);
    if(!is){
        cerr<<"Error opening file\n";
        exit(1);
    }
    cout<<"Reading...\n";
    is.read(reinterpret_cast<char*>(buff),MAX*sizeof(int));
    if(!is){
        cerr<<"Error reading from file\n";
        exit(1);
    }
    is.close();
    for(int j=0;j<MAX;j++) if(buff[j]!=j){
        cerr <<"Incorrect data\n";
        exit(1);
    }
    cout<<"Data is correct\n";
    return 0;
}