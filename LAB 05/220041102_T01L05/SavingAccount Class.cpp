#include "SavingAccount Class.h"

SavingAccount::SavingAccount(){}
SavingAccount::~SavingAccount(){
    cout<<"Voldemort killed the whole family!!\t";
}

//getter functions
string SavingAccount::getAcc_Name(){
    return Acc_Nam;
}
string SavingAccount::getAcc_Hldr_Name(){
    return Acc_Hldr_Nam;
}
string SavingAccount::getAdress(){
    return Adress;
}
double SavingAccount::getAIR(){
    return AIR;
}
double SavingAccount::getBalance(){
    return currenrtBalance;
}

//setter functions
void SavingAccount::setAcc_Name(string a){
    Acc_Nam = a;
}
void SavingAccount::setAcc_Hldr_Name(string a){
    Acc_Hldr_Nam = a;
}
void SavingAccount::setAdress(string a){
    Adress = a;
}
void SavingAccount::setAIR(double a){
    AIR = a;
}
void SavingAccount::setBalance(double a){
    currenrtBalance = a;
}


//rest of the class functions defination
double SavingAccount::calculateInterest(int periodInMonths){
    return (currenrtBalance>=min_bal_fr_interest)? currenrtBalance*AIR*periodInMonths/12:0;
}

void SavingAccount::disburseInterest(int periodInMonths){
    currenrtBalance+=calculateInterest(periodInMonths);
}

bool SavingAccount::operator<(const SavingAccount &other)const{
    return Acc_Nam<other.Acc_Nam;
}