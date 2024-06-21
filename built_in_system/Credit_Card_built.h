
#ifndef CREDIT_CARD_BUILT_H
#define CREDIT_CARD_BUILT_H
#include <string> 
#include "date.h"
using namespace std; 

const double APR = 0.2480; 
class CreditCard {
    private: 
        string number, name; 
        double balance; 
        int limit; 
        Date* due_date; 
    public: 
        CreditCard(const string no, const string nm, int lim, double bal = 0.0): number(no), name(nm), limit(lim), balance(bal) {}
        string getNumber() {return number;}
        string getName() {return name;}
        double getBalance() {return balance;}
        int getLimit() {return limit;}
        Date* get_due_date() const {return due_date;}

        bool IPOS_charge(double price);
        void makePayment(double payment);
        void calculate_due_period();
        friend ostream& operator << (ostream& out, const CreditCard& c);
};  

#endif