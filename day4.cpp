#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int main() {
    fstream myFile;
    myFile.open("day4_input.txt", ios::in);

    if (!myFile.is_open()) {
        exit(EXIT_FAILURE);
    }

    string line;
    int counter = 0;

    while(getline(myFile, line)) {
        stringstream ss(line);
        string firstUpper;
        string firstLower;
        string secondUpper;
        string secondLower;
        

        getline(ss, firstLower, '-');
        getline(ss, firstUpper, ',');
        getline(ss, secondLower, '-');
        getline(ss, secondUpper, ' ');

        int firstUpperInt = stoi(firstUpper);
        int firstLowerInt = stoi(firstLower);
        int secondUpperInt = stoi(secondUpper);
        int secondLowerInt = stoi(secondLower);

        // the logic
        if (firstLowerInt <= secondUpperInt && secondLowerInt <= firstUpperInt) {
            counter++;
        }
    }

    cout << counter << endl;
}

