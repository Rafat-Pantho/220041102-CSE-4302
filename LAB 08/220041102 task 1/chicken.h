#ifndef DB74468E_0C39_4364_8F13_312FB28A4B90
#define DB74468E_0C39_4364_8F13_312FB28A4B90

#include "animal.h"
class Chicken : protected Animal {
    private:
        int dailyEggCount;
    public:
        Chicken();
        Chicken(string n, string hab, int w, int h, int d);
        ~Chicken();

        void make_sound();
        int getEggCount();
        void displayInformation();
        void changeWeight(int _weight);
        
};

#endif /* DB74468E_0C39_4364_8F13_312FB28A4B90 */
