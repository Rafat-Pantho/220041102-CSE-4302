#include <iostream>

using namespace std;

class Calculator{
    private:
        int current_status;

        int get(){
            return current_status;
        }

        void set(int w){
            current_status = w;
        }

    public:
        Calculator(): current_status(0){}
        Calculator(int x): current_status(x){}
        void add(int w){
            current_status += w;
        }
        void subtract(int w){
            current_status -= w;
        }
        void multiply(int w){
            current_status *= w;
        }
        void divide(int w){
            if (w==0)cout<< "Invalid arithmetic operation."<<endl;
            else current_status /= w;
        }
        void clear(){
            current_status = 0;
        }
        void display(){
            cout<<"Calculator display: "<<current_status<<endl;
        }
        ~Calculator(){
            cout << current_status <<"\nDestructor of the Calculator object is called."<<endl;
        }
};

int main(){
    Calculator c;
    c.add(10);c.display();
    c.add(7);c.display();
    c.multiply(31);c.display();
    c.subtract(42);c.display();
    c.divide(7);c.display();
    c.divide(0);c.display();
    c.add(3);c.display();
    c.clear();c.display();

    return 0;
}