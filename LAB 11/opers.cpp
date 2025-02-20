#include <iostream>
#include <fstream>

using namespace std;

class person{
    protected:
        char name[80];
        short age;
    public:
        void getdata(){
            cout<<"Enter name: ";cin>>name;
            cout<<"Enter age: ";cin>>age;
        }
};

int main(){
    person p1;
    p1.getdata();
    ofstream outfile("person.dat",ios::binary);
    outfile.write(reinterpret_cast<char*>(&p1),sizeof(p1));
    outfile.close();
    return 0;
}