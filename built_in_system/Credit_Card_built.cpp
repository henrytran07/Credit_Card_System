
#include "Credit_Card_built.h"
#include <iostream> 
#include <chrono>
#include <ctime> 


using namespace std; 

bool CreditCard::IPOS_charge(double price)
{
    if (price + balance > limit)
        return false; 
    balance += price; 
    return true; 
}

void CreditCard::makePayment(double payment)
{
    balance -= payment; 
}

void CreditCard::calculate_due_period()
{   
    
}

ostream& operator << (ostream &out, CreditCard& c)
{
    out << "Name = " << c.getName()
        << "Number = " << c.getNumber()
        << "Balance = " << c.getBalance()
        << "Limit = " << c.getLimit();
    return out; 
}

