#include "counter.h"


int Counter::getCount(){
    return count;
}

void Counter::increment(){
    count+=incrementing;
}

void Counter::setIncrementStep(int step){
    if(count==0&&step>=0)incrementing = step;
    else cout<<"otherwise, it will print in the console that it cannot set the increment step. The default value is 1."<<endl;
}

void Counter::resetCount(int step = 1){
    count = 0;
    incrementing = step;
}

Counter Counter::operator++(){
    return Counter(++count);
}

Counter Counter::operator++(int){
    return Counter(count++);
}

Counter Counter::operator+=(Counter c){
    return Counter(count+=c.count);
}

Counter Counter::operator+(const Counter &c){
    if(incrementing==c.incrementing)return (count+c.count);
    else{
        cout<<"Cannot add two counters with different incrementing steps"<<endl;
        return Counter();
    }
}

bool Counter::operator<(const Counter &c){
    return (count<c.count);
}

bool Counter::operator>(const Counter &c){
    return (count>c.count);
}

bool Counter::operator>=(const Counter &c){
    return (count>=c.count);
}

bool Counter::operator<=(const Counter &c){
    return (count<=c.count);
}

bool Counter::operator==(const Counter &c){
    return (count==c.count);
}

bool Counter::operator!=(const Counter &c){
    return(count!=c.count);
}