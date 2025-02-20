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
        void showdata(){
            cout<<"\nName: "<<name<<endl<<"Age: "<<age<<endl;
        }
};

int main(){
    person p1;
    ifstream infile;
    infile.open("Group.dat",ios::in|ios::binary);
    infile.seekg(0,ios::end);
    int endposition = infile.tellg();
    int n = endposition/sizeof(person);
    cout<<"\nThere are "<<n<<" records in the file\n";
    cout<<"Enter person number: ";int num;cin>>num;
    int position = (num-1)*sizeof(person);
    infile.seekg(position);
    infile.read(reinterpret_cast<char*>(&p1),sizeof(p1));
    p1.showdata();
    cout<<endl;
    infile.close();
    return 0;
}