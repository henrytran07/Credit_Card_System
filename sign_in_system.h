
#ifndef SIGN_IN_SYSTEM_H
#define SIGN_IN_SYSTEM_H

#include <iostream> 

using namespace std; 

void registeredAccount();
bool login();
unsigned int hashPassword(const string &username, const string &password);
bool accountVerification(const string &input);

#endif
