#ifndef ADBBD299_EED9_466C_B820_859DDE65554D
#define ADBBD299_EED9_466C_B820_859DDE65554D
#include <iostream>
#include <string>
using namespace std;

class SavingAccount{
    public:
        SavingAccount();
        ~SavingAccount();
        double calculateInterest(int periodInMonths);
        void disburseInterest(int periodInMonths);

        //the getter and seter functions of the members
        string getAcc_Name();
        string getAcc_Hldr_Name();
        string getAdress();
        double getAIR();
        double getBalance();
        void setAcc_Name(string a);
        void setAcc_Hldr_Name(string a);
        void setAdress(string a);
        void setAIR(double a);
        void setBalance(double a);
        bool operator<(const SavingAccount &other)const;

    protected:
        private:
            string Acc_Nam, Acc_Hldr_Nam, Adress;
            double AIR, currenrtBalance;
            int min_bal_fr_interest = 1500;
};

#endif /* ADBBD299_EED9_466C_B820_859DDE65554D */
