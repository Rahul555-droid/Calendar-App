/*
Author: Rahul M
Description: Calendar .cpp file containing method definitions for Calender class.
*/

#include <string>
#include <vector>

#include "Reminder.h"
#include "Appointment.h"
#include "Day.h"
#include "Calendar.h"
#include <iostream>
#include <fstream>

using std::string;
using std::vector;
using std::cout;

/*Cunstructors
Default and Parameterised.
They build the calander and also allocates memory to Array of Day*
and initialises them for the same.
*/
Calendar::Calendar(){
this->text = "Calendar";
this->DayStart = 0;
this->numDays = 30;
this->DaysArr = new Day*[numDays];

int DayItr = DayStart;
for (int i = 1; i < numDays+1; i++) 
    DaysArr[i-1] = new Day(i,WeekDays[DayItr%7]);
    DayItr++;
}

Calendar::Calendar(string title,int WeekDay,int num){
this->text = title;
this->DayStart = WeekDay;
this->numDays = num;
this->DaysArr = new Day*[numDays];

int DayItr = DayStart;
for (int i = 1; i < numDays+1; i++) {
    DaysArr[i-1] = new Day(i,WeekDays[DayItr%7]);
    DayItr++;
}
}

//Destructor for garbage Collection.
Calendar::~Calendar(){
for(int i=0;i<numDays;i++)
    delete DaysArr[i]; //deleting dynamically allocated object for Day.

delete [] DaysArr; //deleting Dynamically allocated array DaysArr.
DaysArr = NULL;
 
 }

//Displays calendar.
void Calendar::displayCalandar(){
    cout<<this->text;
    for(int i=1;i<numDays+1;i++)
        cout<<DaysArr[i-1]->getDayNumber()<<" - "<<DaysArr[i-1]->getDayWeek() <<":"<<DaysArr[i-1]->getErrandCount()<<" Errands\n\n";

}

//used to access a day in the array DaysArr. It returns a pointer.
Day* Calendar::AccessDay(int index){
    return DaysArr[index];
}

//Writes calender to file as required.
void Calendar::WriteToFile(string FileName)
{
std::ofstream myfile;
myfile.open (FileName);    
myfile << this->text+"\n";
myfile << "-------------------------\n";

for(int i=1;i<numDays+1;i++)
{
    myfile <<DaysArr[i-1]->getDayNumber()<<" - "<<DaysArr[i-1]->getDayWeek() <<":"<<DaysArr[i-1]->getErrandCount()<<" Errands\n";
    if(DaysArr[i-1]->getErrandCount() != 0) 
        {
        myfile << "Full Details of Day:\n";
        myfile << DaysArr[i-1]->toString();
        }
}

myfile.close();
}



