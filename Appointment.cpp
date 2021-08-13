/*
Author: Rahul M
Description: .cpp file containing method definitions for Appointment Class
*/
#include "Appointment.h"
#include <string>
#include <iostream>

using std::string;
using std::to_string;

/*an alternative could be to make remText private and modify remText inside cunstroctors using setters
but I made remText protected in Reminder so that appointment could just directly access it... 
*/

/*constructors*/
Appointment::Appointment(){
    this->begin_hr =this->begin_mins=0;
    this->end_hr =this->end_mins=0;

   this->remText = "this is my Appointment"; 
}

Appointment::Appointment(int h1,int m1,int h2,int m2,string str)
{
    this->begin_hr = ( h1 >= 0 && h1 < 24 ) ? h1 : 0;
    this->end_hr = ( h2 >= 0 && h2 < 24 ) ? h2 : 0;
    this->begin_mins = ( m1 >= 0 && m1 < 60 ) ? m1 : 0;
    this->end_mins = ( m2 >= 0 && m2 < 60 ) ? m2 : 0;
    this->remText = str; 
}

//dummy destructor
Appointment::~Appointment(){

}

/*Method definitions.*/
//A getter and setter for Appointment text. For time being.
string Appointment::getApp(){
return this->getRem();
}

void Appointment:: setApp(string str){
this->setRem(str);
}

//setters for times to be used if needed.
void Appointment::setBegin(int h,int m){
this->begin_hr = ( h >= 0 && h < 24 ) ? h : 0;
this->begin_mins = ( m >= 0 && m < 60 ) ? m : 0;
}

void Appointment::setEnd(int h,int m){
this->end_hr = ( h >= 0 && h < 24 ) ? h : 0;
this->end_mins = ( m >= 0 && m < 60 ) ? m : 0;
}

//toString() for Appointment.
string Appointment::toString(){
string beginTime = (begin_hr < 10 ? "0" : "")+to_string(begin_hr) + ":"+(begin_mins< 10 ? "0" : "")+to_string(begin_mins);
string endTime = (end_hr < 10 ? "0" : "")+to_string(end_hr) + ":"+(end_mins< 10 ? "0" : "")+to_string(end_mins);
string str = "Appointment – " + beginTime + " - " + endTime + " - " + this->remText;

    return str;

}



    

