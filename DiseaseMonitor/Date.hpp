#ifndef Date_hpp
#define Date_hpp

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Date {
protected:
    int day;
    int month;
    int year;
    bool empty;
public:
    Date();
    Date(string);
    ~Date();
    int getDay();
    int getMonth();
    int getYear();
    void setDate(string);
    void copyDate(Date data){
        day = data.getDay();
        month = data.getMonth();
        year = data.getYear();
        empty = data.isEmpty();
    }
    int compareDate(Date&);
    bool isDateBetween(Date&, Date&);
    void printDate();
    bool isEmpty(){ return empty;}
};

#endif
