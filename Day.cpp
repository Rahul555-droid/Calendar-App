/*
Author: Rahul M
Description: .cpp file containing method definitions for Day Class
*/
#include <string>
#include <vector>
#include <iostream>
#include "Day.h"
#include "Reminder.h"
#include "Appointment.h"

using std::string;
using std::vector;

//A parameterised constructor for Day. Only this is required as we hide access of Day from user.
Day::Day(int num,string str){
this->DayNumber = num;
this->DayWeek = str;
}

Day::~Day(){

}

/* getters for DayNumber and DayWeek. */
int Day::getDayNumber()
{
return this->DayNumber;
}

string Day::getDayWeek()
{
return this->DayWeek;
}
        
//addErand method using vector.pushback()
void Day::addErrand(Reminder* err)
{
    this->errands.push_back(err);
}

//remove errand using vector.erase()
void Day::removeErrand(int index)
{
    std::cout<<errands[index]->toString()<<" - Deleted.";
    this->errands.erase(this->errands.begin() + index);
}

//current count of Errands.
int Day::getErrandCount(){
return this->errands.size();
}

//toString() for Day.
string Day::toString(){
string str = std::to_string(DayNumber)+" - "+DayWeek+":\n";

for(vector<Reminder*>::size_type i = 0; i!= errands.size() ; i++)
        str  = str + "\n\t"+ std::to_string(i+1) +". " + errands[i]->toString();

    return str;
}

