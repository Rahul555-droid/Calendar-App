/*
Author: Rahul M
Description: .cpp file containing method definitions for Reminder Class.
*/
#include "Reminder.h"
#include <string>
#include <iostream>
using std::string;

/*
Cunstructors and destructors
*/
Reminder::Reminder(){
    this->remText = "This is my Reminder";
}
Reminder::Reminder(string str){
    this->remText = str;
}
//A null destructor
Reminder::~Reminder(){
}

//Method definitions
string Reminder::getRem(){
return this->remText;
}

void Reminder::setRem(string str){
this->remText=str;
}

//toString()
string Reminder::toString(){
    string str = "Reminder – " + this->getRem();
    return str;
}

