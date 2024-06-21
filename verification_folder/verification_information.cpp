
#include <iostream>
#include "verification_information.h"
#include <fstream> 

using namespace std; 

bool verification(string& valid_name, string& valid_ssn, int& valid_fico_score)
{
    string user_entered_name, ssn; 
    int user_entered_fico_score; 

    cout << "Please enter your name: ";
    getline(cin, user_entered_name);
    do {
        cout << "Please enter your ssn: ";
        getline(cin, ssn);
    } while (!ssnValidInput(ssn));
    
    cout << "Please enter your fico score: ";
    cin >> user_entered_fico_score;
    ifstream inputFile; 
    inputFile.open("customer_information.txt");   

    if(!inputFile.is_open())
    {
        cerr << "Unable tor read the file. " << endl; 
        exit(1);
    }
    string fico_score; 
    while (inputFile >> valid_name >> valid_ssn >> fico_score)
    {
        try {
            valid_fico_score = stoi(fico_score);
        }
        catch (const invalid_argument& e)
        {
            cerr << "Invalid fico score" << endl; 
            exit(1);
        }

        if (user_entered_name == valid_name && valid_ssn == ssn && user_entered_fico_score == valid_fico_score)
        {
            return true;
        }     
    }
    return false; 
}

bool ssnValidInput(string input)
{
    string ssn_format = ssn_format.substr(3, 0) + "-" + ssn_format.substr(3, 2) + "-" + ssn_format.substr(5, 4);

    if (input == ssn_format)
    {
        return true; 
    }
    return false; 
}