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
        void disIn(int);
        void disOut();
        static int diskCount();
};

void person::disIn(int pn){
    ifstream infile;
    infile.open("PersFile.dat",ios::binary);
    infile.seekg(pn*sizeof(person));
    infile.read((char*)this,sizeof(person));
}
void person::disOut(){
    ofstream outfile;
    outfile.open("PersFile.dat",ios::app|ios::binary);
    outfile.write((char*)this,sizeof(person));
}

int person::diskCount(){
    ifstream infile;
    infile.open("PersFile.dat",ios::binary);
    infile.seekg(0,ios::end);
    return (int)infile.tellg()/sizeof(person);
}

int main(){
    person p1;
    char c;
    do{
        cout<<"Enter person data: "<<endl;
        p1.getdata();
        p1.disOut();
        cout<<"\nDo you want to continue(y/n): ";cin>>c;
        getchar();
    }while(c=='y' || c=='Y');
    int n = person::diskCount();
    cout<<"\nThere are "<<n<<" records in the file\n\n";
    for (int i=0;i<n;i++){
        cout<<"\nperson "<<i+1<<endl;
        p1.disIn(i);
        p1.showdata();
        cout<<endl;
    }
    cout<<endl;
    return 0;
}