#ifndef ED3DC094_58A0_425D_954B_97803BF45738
#define ED3DC094_58A0_425D_954B_97803BF45738

#include "animal.h"
class Cat: private Animal{
    public:
        Cat();
        Cat(string n, string hab, int w, int h);
        ~Cat();

        void make_sound();
        void displayInformation();
        void changeWeight(int _weight);
        
};

#endif /* ED3DC094_58A0_425D_954B_97803BF45738 */
