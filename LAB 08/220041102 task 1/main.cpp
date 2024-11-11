#include <iostream>
#include "animal.h"
#include "cow.h"
#include "chicken.h"
#include "cat.h"
#include "petcat.h"

#include <string>

using namespace std;

int main() {
    Cat c1("cat1", "forest", 5, 5);
    Cow c2("cow2", "farm", 10, 10,10.3);
    Chicken c3("chicken3", "pond", 3, 3, 3);
    Animal a1("a1", "a1", "a1", 1, 1);
    PetCat p1("p1", "p1", 1, 1, "p1");

    c1.make_sound();
    c2.make_sound();
    c3.make_sound();
    a1.make_sound();
    p1.make_sound();

    cout<<endl;

    a1.displayInformation();
    p1.displayInformation();
    c1.displayInformation();
    c2.displayInformation();
    c3.displayInformation();

    p1.changeWeight(10);
    p1.displayInformation();

    return 0;
}