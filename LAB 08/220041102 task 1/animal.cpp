#include "animal.h"
#include "cow.h"
#include "chicken.h"
#include "cat.h"
#include "petcat.h"


using namespace std;

//* describe the animal
Animal::Animal(): nameOfAnimal("Choppa"), habitat_area("Thousand Sunny"), sound("Bokua docta! Tony Tony Choppa"), weight(57), hight(10) {}
Animal::Animal(string s): nameOfAnimal("Choppa"), habitat_area("Thousand Sunny"), sound(s), weight(57), hight(10) {}
Animal::Animal(string n, string hab, string s, int w,int h): nameOfAnimal(n), habitat_area(hab), sound(s), weight(w), hight(h) {}
Animal::~Animal() {}

void Animal::displayInformation(){
    cout<< "Name of Animal: " << nameOfAnimal << "\nHabitat area: " << habitat_area << "\nSound: " << sound << "\nWeight: " << weight << "\nHight: " << hight << endl;
}

void Animal::changeWeight(int _weight){
    weight = _weight;
}

void Animal::make_sound(){
    cout << sound << endl;
}


//* describe the cow
Cow::Cow(): Animal("Moo"), milkProductionInLiters(0){}
Cow::Cow(string n, string hab, int w, int h, double m): Animal(n,hab,"moo",w,h), milkProductionInLiters(m) {}
Cow::~Cow() {}

void Cow::make_sound(){
    cout << "The cow says: ";
    Animal::make_sound();
}

double Cow::getMilkProductionInLiters(){
    return milkProductionInLiters;
}


//* describe the chicken
Chicken::Chicken(): Animal("buck buck"), dailyEggCount(0) {}
Chicken::Chicken(string n, string hab, int w, int h, int e): Animal(n,hab,"buck buck",w,h), dailyEggCount(e) {}
Chicken::~Chicken() {}

void Chicken::make_sound(){
    cout << "The chicken says: " ;
    Animal::make_sound();
}

int Chicken::getEggCount(){
    return dailyEggCount;
}

void Chicken::changeWeight(int _weight){
    Animal::changeWeight(_weight);
}


void Chicken::displayInformation(){
    Animal::displayInformation();
}


//* describe the cat
Cat::Cat(): Animal("meow"){}
Cat::Cat(string n, string hab, int w, int h): Animal(n,hab,"meow",w,h) {}
Cat::~Cat() {}

void Cat::make_sound(){
    cout << "The cat says: ";
    Animal::make_sound();
}


void Cat::displayInformation(){
    Animal::displayInformation();
}


void Cat::changeWeight(int _weight){
    Animal::changeWeight(_weight);
}


//* describe the petcat
PetCat::PetCat(): Cat(), petName("Kitty") {}
PetCat::PetCat(string n, string hab, int w, int h, string pn): Cat(n,hab,w,h), petName(pn) {}
PetCat::~PetCat() {}

void PetCat::make_sound(){
    cout << petName << "! ";
    Cat::make_sound();
}

void PetCat::displayInformation(){
    Cat::displayInformation();
}

void PetCat::changeWeight(int _weight){
    Cat::changeWeight(_weight);
}
