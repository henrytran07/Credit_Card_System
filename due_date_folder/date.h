#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Date{
private:
    int day, month, year;
public:
    Date() : year(2024) { initializeRandom(); randomMonth(); randomDay(month); }
    
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }
    
    void randomDay(int month);
    void randomMonth();
    void initializeRandom();
    vector<string> dueDate();       
};

#endif
