#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
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
        

        getline(ss, firstUpper, '-');
        getline(ss, firstLower, ',');
        getline(ss, secondUpper, '-');
        getline(ss, secondLower, ';');

        int firstUpperInt = stoi(firstUpper);
        int firstLowerInt = stoi(firstLower);
        int secondUpperInt = stoi(secondUpper);
        int secondLowerInt = stoi(secondLower);

        if ((firstUpperInt <= secondUpperInt && firstLowerInt >= secondLowerInt) || (secondUpperInt <= firstUpperInt && secondLowerInt >=firstLowerInt))
            counter++;
    }

    cout << counter << endl;
}