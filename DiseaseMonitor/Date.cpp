#include "Date.hpp"
#include <string.h>
#include <fstream>
#include <iostream>
#include <sstream>

Date::Date() {
}

Date::Date(string input) {
    setDate(input);
}

Date::~Date() {
}

int Date::getDay() {
    return day;
}

int Date::getMonth() {
    return month;
}

int Date::getYear() {
    return year;
}

void Date::setDate(string var) {
    if (var == "-") {
        empty = true;
        day = month = year = 0;

    } else {
        stringstream date(var);
        string d, m, y;
        getline(date, d, '-');
        getline(date, m, '-');
        getline(date, y, '-');
        //cout << d << " " << m << " "<< y << endl;
        day = stoi(d);
        month = stoi(m);
        year = stoi(y);
        empty = false;
    }
    // void empty;
}

int Date::compareDate(Date &d1) {
    if (year < d1.getYear()) return -1;
    else if (year > d1.getYear()) return 1;
    else {
        if (month < d1.getMonth()) return -1;
        else if (month > d1.getMonth()) return 1;
        else {
            if (day < d1.getDay()) return -1;
            else if (day == d1.getDay()) return 0;
            else return 1;
        }
    }
}

bool Date::isDateBetween(Date &d1, Date &d2) {
    if ((compareDate(d1) < 0 && compareDate(d2) > 0) || (compareDate(d1) > 0 && compareDate(d2) < 0))
        return 1;
    else if (compareDate(d1) == 0 && compareDate(d2)<  0)
        return 1;
    else if (compareDate(d1) > 0 && compareDate(d2) == 0)
        return 1;

    else return 0;
}

void Date::printDate() {
    cout << day << "-" << month << "-" << year;
}
