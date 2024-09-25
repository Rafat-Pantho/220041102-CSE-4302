#include<iostream>
#include <string.h>

using namespace std;

class BankAccount{
    private:
        string acc_num, name_of_cliant,type;
        double balance;
        const double min_balance;

    public:
        static int total,current,total_tax;

        BankAccount():acc_num(""),name_of_cliant(""),type(""),balance(0.0),min_balance(0.0){
            total++;
            current++;
        }
        BankAccount(string a, string b, string c, float d, float const e):acc_num(a),name_of_cliant(b),type(c),balance(d),min_balance(e){
            total++;
            current++;
        }
        BankAccount(float const a):min_balance(a){
            total++;
            current++;
        }
        void showBalance(){
            cout<<"Current Balance: "<<balance<<endl;
        }
        void deposit(float a){
            balance+=a;
        }
        void giveInterest(){
            
        }
        void withdrawal(float a){
            if (a<min_balance){
                cout<<"AMOUNT IS LESS THEN THE MINIMUM"<<endl;
                return;
            }
            if (a>balance){
                cout<<"INSUFFICINT BALANCE"<<endl;
                return;
            }
            balance-=a;
        }
        double Balance()const {
            return balance;
        }
        ~BankAccount(){
            cout<<"Account of Mr. "<<name_of_cliant<<" with account no "<<acc_num<<" is destroyed with balance BDT "<<balance<<" ."<<endl;
            current--;
        }
};

void display_stat(){

}

BankAccount Large(const BankAccount a, const BankAccount b){
    if (a.Balance()>b.Balance()) return a;
    else return b;
}