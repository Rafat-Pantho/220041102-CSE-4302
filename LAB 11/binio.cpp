#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 100;
int buff[MAX];

int main(){
    for (int j=0;j<MAX; j++)buff[j]=j;
    ofstream os("edata.dat",ios::binary);
    os.write(reinterpret_cast<char*>(buff), MAX*sizeof(int));
    os.close();
    for (int j=0;j<MAX;j++)buff[j]=0;
    ifstream is("edata.dat",ios::binary);
    is.read(reinterpret_cast<char*>(buff),MAX*sizeof(int));
    for(int j =0; j<MAX;j++) if (buff[j]!=j){
        cout<<"Incorrect data!\n";
        return 1;
    }
    cout<<"Data is cottect\n";
    return 0;
}