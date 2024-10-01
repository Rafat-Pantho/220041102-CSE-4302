#ifndef C7EBEFD2_5492_43BA_B011_F24947A63A6F
#define C7EBEFD2_5492_43BA_B011_F24947A63A6F

#include <iostresm>
#include <string>
#include <time>

using namespace std;

enum Month{
    January=1,February,March,April,May,June,July,August,September,October,November,December
};

class Date_of_bitch{
    private:
        int day,year;
        Month month;
}

class Employee{
    private:
        string name;
        Date_of_bitch date_of_birth;
        int salary;

        //geter functions
        string get_name();
        string get_date_of_birth();
        int get_salary();
        //setter functions
        void set_name(string name);
        void set_date_of_birth(Date_of_bitch date_of_birth);
        void set_salary(int salary);
};


#endif /* C7EBEFD2_5492_43BA_B011_F24947A63A6F */
