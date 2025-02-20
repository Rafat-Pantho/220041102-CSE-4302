#include <iostream>
#include <fstream>

using namespace std;

class person{
    protected:
        char name[80];
        short age;
    public:
        void getdata(){
            cout<<"\nEnter name: ";cin>>name;
            cout<<"Enter age: ";cin>>age;
        }
        void showdata(){
            cout<<"\nName: "<<name<<endl<<"Age: "<<age<<endl;
        }
};

int main(){
    char c;
    person p1;
    fstream file;
    file.open("Group.dat",ios::app|ios::out|ios::in|ios::binary);
    do{
        p1.getdata();
        file.write(reinterpret_cast<char*>(&p1),sizeof(p1));
        cout<<"\nDo you want to continue(y/n): ";cin>>c;
    }while(c=='y' || c=='Y');
    file.seekg(0);
    file.read(reinterpret_cast<char*>(&p1),sizeof(p1));
    while(!file.eof()){
        p1.showdata();cout<<endl;
        file.read(reinterpret_cast<char*>(&p1),sizeof(p1));
    }
    cout<<endl;
    file.close();
    return 0;
}