#include <iostream>
#include <string>

using namespace std;

class UFO{
    private:
        int flight_num;
        string destination;
        float distance,MaxFuelCapacity;

        double CalFuel(){
            if(distance<=1000)return 500;
            else if(distance<=2000)return 1100;
            else return 2200;
        }

    public:
        UFO():flight_num(0),destination(""),distance(0),MaxFuelCapacity(0){}

        void FeedInfo(int a, string b, float c, float d){
            flight_num = a;
            destination = b;
            distance = c;
            MaxFuelCapacity = d;
        }

        void ShowInfo(){
            cout<<"Flight Number: "<<flight_num<<endl;
            cout<<"Destination: "<<destination<<endl;
            cout<<"Distance: "<<distance<<endl;
            cout<<"Max Fuel Capacity: "<<MaxFuelCapacity<<endl;
            if( MaxFuelCapacity>=CalFuel())cout<<"Fuel capacity is fit for this flight distance."<<endl;
            else cout<<"Not sufficient Fuel Capacity for this flight."<<endl;
        }
};

int main(){
    UFO panthos_ufo;
    int a;
    string b;
    float c;
    float d;
    cout<<"Enter the flight number: "<<endl;cin>>a;
    cout<<"Enter the destination: "<<endl;cin.ignore();getline(cin,b);
    cout<<"Enter the distance: "<<endl;cin>>c;
    cout<<"Enter the max fuel capacity: "<<endl;cin>>d;
    panthos_ufo.FeedInfo(a,b,c,d);
    panthos_ufo.ShowInfo();
    return 0;
}