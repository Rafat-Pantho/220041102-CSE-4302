#include <iostream>

using namespace std;

class MyString{
    private:
        char * str;

    public:
        MyString():str('\0'){}
        MyString(char * s):str(s){}
        ~MyString(){
            delete [] str;
        }

        void assignString(char s[]){
            delete [] str;
            str=new char[1000];
            int i=0;
            while(s[i]!='\0'){
                str[i]=s[i];
                i++;
            }
            str[i]='\0';
        }

        int length(){
            int i=0;
            for(;str[i]!='\0';i++);
            return i;
        }

        char * print(){
            return str;
        }
};

void sortbylength(MyString *arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;i<n;i++){
            if(arr[i].length()>arr[j].length()) swap(arr[i],arr[j]);
        }
    }
}

int main(){
    MyString arr[10];
    for(int i=0;i<10;i++){
        char s[1000];
        cin>>s;
        arr[i].assignString(s);
    }
    sortbylength(arr,10);
    for (int i=0;i<10;i++)cout<<arr[i].print()<<endl;

    return 0;
}