/*
Author: Rahul Mohta
Date: 28th June 2021
Description: Appointment Class Header file.
*/
#pragma once
#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include "Reminder.h"

using std::string;

class Appointment : public Reminder{
private: 
    int begin_hr;
    int begin_mins;
    int end_hr;
    int end_mins;
public:
    //cunstructors
    Appointment();
    Appointment(int,int,int,int,string);
    //destructor
    ~Appointment();

    //methods
    string getApp();
    void setApp(string);
    void setBegin(int,int);
    void setEnd(int,int);
    string toString();


};

#endif