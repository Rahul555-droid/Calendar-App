/*
Author: Rahul M
Description: Calendar header file.
*/

#pragma once
#ifndef Calendar_H
#define Calendar_H

#include <string>
#include <vector>

#include "Reminder.h"
#include "Appointment.h"
#include "Day.h"

using std::string;
using std::vector;


class Calendar{
private:
    string text;
    int DayStart; //In range 0 to 6 for the Array WeekDays
    int numDays;
    Day** DaysArr;
    string WeekDays[7] = { "Monday", "Tuesday", "Wednesday", "Thursday","Friday","Saturday","Sunday" };
public:
        //constructors and destructor.
        Calendar();
        Calendar (string,int,int); 
        ~Calendar();  //used for deleting the Day* array.

        void displayCalandar();
        
        void WriteToFile(string);

        //used to access a day in the array DaysArr. It returns a pointer.
        Day* AccessDay(int);

};


#endif