#include <iostream>
#include <string>

using namespace std;

class Temperature{
    private:
        double temp;
        string unit;

    public:
        Temperature(): temp(0.0),unit("C"){}

        void assign(double a, string n){
            if(n!="C"&&n!="F"&&n!="K"){
                cout<<"Invalid unit"<<endl;
                return;
            }
            if((n=="K"&&a<0)||(n=="C"&&a< -273.15)||(n=="F"&&a< -459.67)){
                cout<<"Invalid value"<<endl;
                return;
            }
            temp = a;
            unit = n;
        }

        double convert(string s){
            if(unit == s)return temp;
            if(unit == "C" && s== "K")return temp+273.15;
            if(unit == "C" && s== "F")return temp*9/5+32;
            if(unit == "F" && s== "C")return (temp-32)*5/9;
            if(unit == "F" && s== "K")return (temp-32)*5/9+273.15;
            if(unit == "K" && s== "C")return temp-273.15;
            if(unit == "K" && s== "F")return (temp-273.15)*9/5+32;

            return 0;
        }

        void print() {
            cout<< "The temperature is "<<temp<<" "<<unit<<"."<<endl;
        }
};

int main(){
    Temperature t;
    t.assign(100, "C");
    t.print();
    t.assign(100, "F");
    t.print();
    t.assign(100, "K");
    t.print();
    t.assign(0, "C");

    double conv_temp = t.convert("F");
    cout<<"Converted temperature is: "<<conv_temp<<endl;

    return 0;
}