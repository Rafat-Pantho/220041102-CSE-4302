#include <iostream>
#include "SavingAccount Class.h"
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int timeGEN(){
    return rand()%36+6;
}

double genAmount(){
    return rand()%1500+1000;
}

string Y_N_GEN(){
    return (rand()%2)?"YES":"NO";
}

void deposite(SavingAccount acc,double amount){
    if (amount > 0)acc.setBalance(acc.getBalance()+amount); 
}

void withdrawl(SavingAccount acc,double amount){
    if(amount <= acc.getBalance())acc.setBalance(acc.getBalance()-amount);
    else cout<<"Insufficient Balance"<<endl;
}

void ShowInterestAll(SavingAccount (&acc)[100]){
    for(int i=0;i<100;i++){
        cout<<"Enter the time of interest: ";
        int time=timeGEN();cout<<time<<endl;
        cout<<"Interest earned: "<<acc[i].calculateInterest(time)<<endl<<"Do you wanna disburse the interest?\n\tYES/NO which?\n"<<endl;
        string choice=Y_N_GEN();cout<<choice<<endl;
        if(choice=="YES")acc[i].disburseInterest(time);
        cout<<endl;
        cout<<"DO YOU Wanna WITHDRAW ? YES or NO"<<endl;
        choice=Y_N_GEN();cout<<choice<<endl;
        if(choice=="YES"){
            cout<<"Enter the amount: ";
            double amount=genAmount();cout<<amount<<endl;
            withdrawl(acc[i],amount);
        }
        cout<<endl;
        cout<<"DO YOU wanna DEPOSITE ? YES or NO"<<endl;
        choice=Y_N_GEN();cout<<choice<<endl;
        if(choice=="YES"){
            cout<<"Enter the amount: ";
            double amount=genAmount();cout<<amount<<endl;
            deposite(acc[i],amount);
        }
        cout<<endl;

        cout<<"Account Name: "<<acc[i].getAcc_Name()<<"\n\tAccount Current Balance: "<<acc[i].getBalance()<<endl<<endl;
    }
}

void ShowAllAlphabetically(SavingAccount (&acc)[100]){
    sort(acc,acc+100);
    for(int i=0;i<100;i++)cout<<"Account Name: "<<acc[i].getAcc_Name()<<"\n\tAccount Current Balance: "<<acc[i].getBalance()<<endl<<endl;
}

string NameGenerator(){
    string name;
    for(int i=0;i<rand()%12+4;i++)name.push_back(rand()%26+65);
    name.push_back(' ');
    for(int i=0;i<rand()%12+4;i++)name.push_back(rand()%26+65);
    return name;
}

string AdressGenerator(){
    string name;
    for(int i=0;i<rand()%12+4;i++)name.push_back(rand()%26+65);
    name.push_back(',');
    for(int i=0;i<rand()%12+4;i++)name.push_back(rand()%26+65);
    name.push_back(',');
    for(int i=0;i<rand()%12+4;i++)name.push_back(rand()%26+65);
    name.push_back(',');
    for(int i=0;i<rand()%12+4;i++)name.push_back(rand()%26+65);
    name.push_back(',');
    for(int i=0;i<rand()%12+4;i++)name.push_back(rand()%26+65);

    return name;
}

double generateInterest(){
    return rand()%5+2;
}

double generateBalance(){
    return rand()%50000+100;
}

int main(){
    SavingAccount acc[100];
    for(int i=0;i<100;i++){
        acc[i].setAcc_Name(NameGenerator());
        acc[i].setAcc_Hldr_Name(NameGenerator());
        acc[i].setAdress(AdressGenerator());
        acc[i].setAIR(generateInterest());
        acc[i].setBalance(generateBalance());
    }

    ShowInterestAll(acc);
    cout<<endl<<endl;
    cout<<"\t\tShowing alphapetically!"<<endl;
    ShowAllAlphabetically(acc);

    return 0;
}