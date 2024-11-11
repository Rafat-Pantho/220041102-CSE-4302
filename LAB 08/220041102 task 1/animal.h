#ifndef D81D482E_400A_49C0_BBBD_1655FBDFF5DF
#define D81D482E_400A_49C0_BBBD_1655FBDFF5DF

#include <string>
#include <iostream>

using namespace std;

class Animal{
    private:
        string nameOfAnimal, habitat_area,sound;
        int weight,hight;

    public:
        Animal();
        Animal(string s);
        Animal( string n, string hab, string s, int w, int h );
        ~Animal();

        void displayInformation();

        void changeWeight( int _weight );
        void make_sound();
};

#endif /* D81D482E_400A_49C0_BBBD_1655FBDFF5DF */
