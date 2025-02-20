#include <iostream>
#include <fstream>

using namespace std;

class person{
    protected:
        char name[80];
        short age;
    public:
        void showdata(){
            cout<<"Name: "<<name<<endl<<"Age: "<<age<<endl;
        }
};

int main(){
    person p1;
    ifstream infile("person.dat",ios::binary);
    infile.read(reinterpret_cast<char*>(&p1),sizeof(p1));
    p1.showdata();
    infile.close();
    return 0;
}