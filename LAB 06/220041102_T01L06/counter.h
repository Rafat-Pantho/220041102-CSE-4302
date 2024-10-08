#ifndef C2D1CB53_0F48_421A_8C56_7B9E25085580
#define C2D1CB53_0F48_421A_8C56_7B9E25085580

#include <iostream>
using namespace std;

class Counter{
    private:
        int count;
        int incrementing;
    
    public:
        Counter():incrementing(1){}
        Counter(int c):count(c),incrementing(1){}
        Counter(int c,int i):count(c),incrementing(i){}
        ~Counter(){}
        int getCount();
        void setIncrementStep(int step);
        void increment();
        void resetCount(int step);
        Counter operator++();
        Counter operator++(int);
        Counter operator+=(Counter c);
        Counter operator+(const Counter &c);
        bool operator>(const Counter &c);
        bool operator<(const Counter &c);
        bool operator>=(const Counter &c);
        bool operator<=(const Counter &c);
        bool operator==(const Counter &c);
        bool operator!=(const Counter &c);
};

#endif /* C2D1CB53_0F48_421A_8C56_7B9E25085580 */
