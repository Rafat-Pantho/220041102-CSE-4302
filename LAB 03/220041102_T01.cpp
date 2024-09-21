#include <iostream>

using namespace std;

class Counter {
    private:
        int count;
        int incrementing;

    public:
        Counter() : count(0),incrementing(1){}

        void setIncrementStep(int step){
            incrementing = step;
        }

        int getCount(){
            return count;
        }

        void increment(){
            count += incrementing;
        }

        void resetCount(){
            count = 0;
        }
};

int main(){
    Counter c;
    c.setIncrementStep(376);
    cout << c.getCount() << endl;
    c.increment();
    cout << c.getCount() << endl;
    c.resetCount();
    cout << c.getCount() << endl;
    return 0;
}