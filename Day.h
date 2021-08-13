/*
Author: Rahul M
Description:  Header file for Day Class.
*/
#pragma once
#ifndef DAY_H
#define DAY_H

#include <string>
#include <vector>
#include "Reminder.h"
#include "Appointment.h"

using std::string;
using std::vector;

class Day{
    private:
        int DayNumber;
        string DayWeek;
        vector<Reminder*> errands;
    public:
        Day(int,string); //make sure that both inputs are valid and use main for this.
        ~Day();
        int getDayNumber();
        string getDayWeek();
        void addErrand(Reminder*);
        void removeErrand(int);
        string toString();
        int getErrandCount();
};


#endif