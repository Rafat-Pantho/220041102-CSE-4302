#ifndef C5C8113E_C27F_4FDD_A783_9BF8DA641809
#define C5C8113E_C27F_4FDD_A783_9BF8DA641809

#include "cat.h"

class PetCat : public Cat{
    private:
        string petName;

    public:
        PetCat();
        PetCat(string n, string hab, int w, int h, string pn);
        ~PetCat();
        void make_sound();
        void displayInformation();
        void changeWeight(int _weight);
};

#endif /* C5C8113E_C27F_4FDD_A783_9BF8DA641809 */
