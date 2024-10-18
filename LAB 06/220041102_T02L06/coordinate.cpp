#include <iostream>
#include <cmath>
#include "coordinate.h"
using namespace std;




void coordinate::display(){
    cout<<x<<","<<y<<endl;
    cout<<getDistance()<<endl<<endl;
}

float coordinate::operator - (coordinate &c){
    return sqrt( (x-c.x)*(x-c.x) + (y-c.y)*(y-c.y) );
}

float coordinate::getDistance(){
    return sqrt( x*x + y*y );
}

void coordinate::move_x(float val){
    x+=val;
}

void coordinate::move_y(float val){
    y+=val;
}

void coordinate::move(float x_val, float y_val){
    x+=x_val;
    y+=y_val;
}


bool coordinate::operator>(const coordinate &c){
    return (getDistance()>c.getDistance());
}

bool coordinate::operator<(const coordinate &c){
    return (getDistance()<c.getDistance());
}

bool coordinate::operator==(const coordinate &c){
    return (getDistance()==c.getDistance());
}

bool coordinate::operator!=(const coordinate &c){
    return (getDistance()!=c.getDistance());
}

bool coordinate::operator>=(const coordinate &c){
    return (getDistance()>=c.getDistance());
}

bool coordinate::operator<=(const coordinate &c){
    return (getDistance()<=c.getDistance());
}