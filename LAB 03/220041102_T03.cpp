#include <iostream>

using namespace std;

class Time{
    private:
        int hr,min,sec;

    public:
        Time(): hr(0),min(0),sec(0){}
        Time(int h, int m, int s): hr(h),min(m),sec(s){}
        
        int hours(){
            return hr;
        }

        int minutes(){
            return min;
        }

        int seconds(){
            return sec;
        }

        void reset(int h, int m, int s){
            hr = (h>=0 && h<24)? h:0;
            min = (m>=0 && m<60)? m:0;
            sec = (s>=0 && s<60)? s:0;
        }

        void advance(int h, int m, int s){
            sec+=s;
            min+=sec/60;
            sec%=60;
            min+=m;
            hr+=min/60;
            min%=60;
            hr+=h;
            hr%=24;
        }

        void print(){
            cout << hr << ":" << min << ":" << sec << endl;
        }
};

int main(){
    Time t;
    t.reset(10, 30, 20);
    t.print();
    t.advance(1, 20, 30);
    t.print();
    t.advance(34,56,34);
    t.print();
    t.reset(3, 59, 59);
    t.print();

    return 0;
}