/*
Author: Rahul M
Description: Reminder Header file.
*/
#pragma once
#ifndef REMINDER_H
#define REMINDER_H
#include <string>
using std::string;

class Reminder{
protected:
//private:
  string remText;
public:
      //constructors
  Reminder();//default constructor
  Reminder(string);
 //destructor
  ~Reminder();
 
 //methods
  string getRem();
  void setRem(string);
  virtual string toString();
};

#endif