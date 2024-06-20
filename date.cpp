#include "date.h"
#include <ctime>
#include <sstream>

const int MONTHS = 12;
const int NUMBERS_OF_YEARS = 5;
const int NUMBERS_OF_MONTHS = NUMBERS_OF_YEARS * MONTHS;

void Date::initializeRandom() {
    srand(static_cast<unsigned int>(time(0)));
}

void Date::randomDay(int month) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            day = rand() % 31 + 1;
            break;
        case 4: case 6: case 9: case 11:
            day = rand() % 30 + 1;
            break;
        case 2:
            day = rand() % 28 + 1; // Simplified for non-leap year
            break;
        default:
            day = 1;
    }
}

void Date::randomMonth() {
    month = rand() % 12 + 1;
}

vector<string> Date::dueDate() {
    vector<string> due_dates;
    int current_month = month;
    int current_year = year;
    
    for (int i = 0; i < NUMBERS_OF_MONTHS; ++i) {
        current_month++;
        if (current_month > 12) {
            current_month = 1;
            current_year++;
        }
        
        ostringstream oss;
        oss << (current_month < 10 ? "0" : "") << current_month << "-"
            << (day < 10 ? "0" : "") << day << "-" << current_year;
        due_dates.push_back(oss.str());
    }
    return due_dates;
}

