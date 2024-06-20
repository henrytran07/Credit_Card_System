#include "sign_in_system.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype> 

using namespace std;

unsigned int hashPassword(const string &username, const string &password)
{
    unsigned int result = 0;

    for (unsigned int ch : username)
    {
        result = ch + (result << 4) + (result << 10) - result;
    }

    for (unsigned int ch : password)
    {
        result = ch + (result << 4) + (result << 10) - result;
    }

    return result;
}

bool accountVerification(const string &input)
{
    bool has_alpha = false;
    bool has_special = false;
    
    for (char ch : input)
    {
        if (isalpha(ch))
        {
            has_alpha = true;
        }
        else if (ch == '!' || ch == '@' || ch == '#' || ch == '$' || ch == '%' || ch == '^' || ch == '&' || ch == '*')
        {
            has_special = true;
        }
    }

    return has_alpha && has_special;
}

void registeredAccount()
{
    string username;
    do
    {
        cout << "Please enter your username for the register (having letters + alpha letters): ";
        cin >> username;
    } while (!accountVerification(username));

    string password, verified_password;

    do
    {
        do
        {
            cout << "Please enter your password for the register (having letters + special characters): ";
            cin >> password;
        } while (!accountVerification(password));

        cout << "Please re-enter your password for the account verification: ";
        cin >> verified_password;
    } while (password != verified_password);

    ofstream outputFile("customer_information_login.txt", ios::app);

    if (!outputFile.is_open())
    {
        cerr << "Unable to read the file. " << endl;
        exit(1);
    }

    unsigned int hash_password = hashPassword(username, password);

    outputFile << username << endl;
    outputFile << hash_password << endl;

    outputFile.close();
}

bool login()
{
    ifstream inputFile("customer_information_login.txt");

    if (!inputFile.is_open())
    {
        cerr << "Unable to read the file" << endl;
        exit(1);
    }

    string username, password;
    cout << "Please enter your username: ";
    cin >> username;

    cout << "Please enter your password: ";
    cin >> password;

    unsigned int hash_password = hashPassword(username, password);

    string valid_username;
    unsigned int valid_password;

    while (inputFile >> valid_username >> valid_password)
    {
        if (username == valid_username && valid_password == hash_password)
        {
            return true;
        }
    }

    return false;
}

