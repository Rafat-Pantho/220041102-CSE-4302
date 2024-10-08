#include <iostream>
#include "coordinate.h"
#include <ctime>

using namespace std;

void randomAssignment(coordinate c[], int size){
    ///Write code to assign random abscissa and ordinate to elements of c
    srand(time(0));
    for(int i=0;i<size;i++) c[i]=coordinate(rand()/100,rand()/100);
    //*as no particular range given i am using 0-99;
}
void sort(coordinate c[], int size){
    //bubble sor 
    for(int i=0;i<size-1;i++) for(int j=i+1;j<size;j++) if(c[i]>c[j])swap(c[i],c[j]);
}
int main(){
    coordinate coord[10];
    randomAssignment(coord,10);
    sort(coord,10);
    for(int i=0;i<10;i++)coord[i].display();
    return 0;
}
