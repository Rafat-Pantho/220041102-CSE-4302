#include "employee.h"

//declear getter functions
string Employee::get_name(){
    return name;
}
Date_of_bitch Employee::get_date_of_birth(){
    return date_of_birth;
}
int Employee::get_salary(){
    return salary;
}

//declear setter functions
void Employee::set_name(string name1){
    if(Word_count_in_str(name1)>1)name = name1;
    else name = "John Doe";
}

void Employee::set_date_of_birth(Date_of_bitch s){
    date_of_birth = s;
}

int Word_count_in_str(string s){
    int count = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]==' '&&i!=s.length()-1 && i!=0&&s[i-1]!=' ')count++;
    }
    return count+1;
}