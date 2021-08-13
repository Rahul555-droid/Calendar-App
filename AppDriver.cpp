/*
Author: Rahul M
Description: Sort of a "driver" .cpp file, containing Main().
*/

#include <string>
#include <vector>

#include<stdlib.h>
#include "Reminder.h"
#include "Appointment.h"
#include "Day.h"
#include "Calendar.h"
#include <iostream>
#include <fstream>

using namespace std;


int main(){
    int input;
    cout<<"Welcome to CSE240 Calendar\n\n1. Build a new Calendar\n2. Exit\n>> ";

    //First menu    
    bool run = true;
    while(run)
    {
        cin>>input;
        switch(input)
        {
            case 1:
                run = false;
                break;
            
            case 2:
                run = false;
                exit(0);
                break;

            default:
                cout<<"Wrong input.\n Try Again\n >>";

        }
    }

    string cal_text;
    cout<<"Building a new calendar.\n\n";
    cout <<"Give your calendar a title : \n";
	  cin.ignore ();
    getline(cin,cal_text);
    
    int numdays;
    cout<<"How many days does this calendar have? ";
    cin>>numdays;
    while(numdays <1 )
        {
            cout<<"No. of days in Calendar must be > 1.\n Enter valid value >> ";
            cin>>numdays;
        }
    
    int weekday;
    string menu = "What day does your calendar start on?\n";
    menu = menu +   "1. Monday\n"+
                    "2. Tuesday\n"+
                    "3. Wednesday\n"+
                    "4. Thursday\n"+
                    "5. Friday\n"+
                    "6. Saturday\n"+
                    "7. Sunday\n"+
                    "Selection >> ";
    cout<<menu;
    cin>>weekday;

    while(weekday <1 || weekday >7)
        {
            cout<<"Input Day not in Range (1-7) Try Again\n. >> ";
            cin>>weekday;
        }

    ///builds calendar cal.
    Calendar cal(cal_text,weekday,numdays);
    
    cout<<"Your Calendar has been created.\n";

    menu = "What would you like to do?\n";
    menu = menu +   "1. Display Whole Calendar\n"+
                    "2. Display a Single Day\n"+
                    "3. Add an Errand\n"+
                    "4. Delete an Errand\n"+
                    "5. Save to a file\n"+
                    "0. Exit\n"+
                    "Selection >> ";
    
    int index;
    Day* DayP;
    while(true)
    {   
        cout<<menu;
        cin>>input;
        
            if(input == 1)
                {
                cal.displayCalandar();
                }

            else if(input == 2)
                {
                cout<<"Enter Day to display >> ";
                cin>>index;
                DayP = cal.AccessDay(index);
                cout<<DayP->toString()<<"\n\n";
                }

            else if (input == 3)
                {
                cout<<"* Add an Errand *\n";
                cout<<"Select which day you want to add an Errand to:\n Day (1 - "<<numdays<< " )" << " >> ";
                cin>>index;
                DayP = cal.AccessDay(index);
                
                string menu_ = "What type of Errand?\n1. Reminder\n2. Appointment\n0. Back to main menu>>";
                int input_;
                cout<<menu_;
                cin>>input_;
                
                if (input_ == 1)
                {
                    string rtext;
                    cout<<"Enter Remainter text: ";
                      cin.ignore ();
                    getline(cin,rtext);
                    DayP->addErrand(new Reminder(rtext));
                }
                else if (input_ == 2)
                {
                int h1,h2,m1,m2;
                cout<<"Enter start time hour (24-hour clock): ";
                cin>> h1;
                cout << "Enter start time minutes: ";
                cin>>m1;
                cout<<"Enter end time hours (24-hour clock):";
                cin>>h2;
                cout<<"Enter end time minutes:";
                cin>>m2;
                cout<<"Enter reminder text:";
                string atext;
                  cin.ignore ();
				getline(cin,atext);
                DayP->addErrand(new Appointment(h1,m1,h2, m2,atext));
                    
                }
                else if (input_ == 0)
                    continue; //back to main menu.
                
                else
                    cout<<"\nWrong input\n";
                
                }

            else if (input == 4)
                {
                cout<<" *Remove an Errand* \n";
                cout<<"Select which day you want to remove an Errand to:\n Day (1 - "<<numdays<< " )" << " >> ";
                cout<<"\n 0. Back to main menu\n >>";
                cin>>index;
                
                if (index == 0) //back to main menu.
                    continue;
                
                DayP = cal.AccessDay(index);
                cout <<"You have chosen \n\t";
                cout << DayP->toString()<<"\n";
                cout << "0 . Back to main menu\n";
                cout <<"Which would you like to delete?\n >>";
                int remIndex; 
                cin >> remIndex;
                
                if (remIndex == 0) //back to main menu.
                    continue; 
                DayP->removeErrand(remIndex);
                }
            
            else if(input == 5){
                string fileName;
                cout<<"Save Calendar to file"<<"\nPlease enter the filename to store to\n >>";
				  cin.ignore ();
                getline(cin,fileName);
                cal.WriteToFile(fileName);
            }

            else if(input == 0)
                    break;

            else
                cout<<"\nWrong input.\n Try Again\n";
    }

return 0;
    }