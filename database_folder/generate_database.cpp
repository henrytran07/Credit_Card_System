#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <fstream>
#include <numeric> 
#include <algorithm>
#include <random> 
using namespace std;

const int DATA_BASE_SIZE = 100;

char generateUpperCaseLetter() {
    return 'A' + rand() % 26;
}

int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

string generateName() {
    string name;
    int length = randomInt(5, 20);
    name += generateUpperCaseLetter(); // First letter uppercase

    for (int i = 1; i < length; i++) {
        name += 'a' + rand() % 26; // Random lowercase letters
    }

    return name;
}

string generateSSN() {
    string ssn;
    for (int i = 0; i < 9; i++) {
        ssn += '0' + randomInt(0, 9); // Random digit between 0 and 9
    }

    ssn = ssn.substr(0, 3) + "-" + ssn.substr(3, 2) + "-" + ssn.substr(5, 4);
    return ssn;
}

int generate_Fico_score()
{
    vector<int>fico_score(551);
    iota(fico_score.begin(), fico_score.end(), 300);
    random_device rd; 
    mt19937 g(rd());
    shuffle(fico_score.begin(), fico_score.end(), g);

    return fico_score[0];
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<string> customer_information;
    ofstream customerFile("customer_information.txt", ios::app);

    if (!customerFile.is_open()) {
        cerr << "Unable to open the file." << endl;
        return 1;
    }

    for (int i = 0; i < DATA_BASE_SIZE; i++) {
        string name = generateName();
        string ssn = generateSSN();
        int fico_score = generate_Fico_score();
        customerFile << name << endl;
        customerFile << ssn << endl;
        customerFile << fico_score << endl; 
    }

    customerFile.close();


    return 0;
}
