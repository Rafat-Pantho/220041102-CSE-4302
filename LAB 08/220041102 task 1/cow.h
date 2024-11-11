#ifndef C5AE9BD2_AEBF_4459_A3CC_89610B213C85
#define C5AE9BD2_AEBF_4459_A3CC_89610B213C85

#include "animal.h"
class Cow : public Animal {
    private:
        double milkProductionInLiters;
    public:
        Cow();
        Cow(string n, string hab, int w, int h, double m);
        ~Cow();

        void make_sound();
        double getMilkProductionInLiters();
};

#endif /* C5AE9BD2_AEBF_4459_A3CC_89610B213C85 */
