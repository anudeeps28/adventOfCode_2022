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
        

        getline(ss, firstUpper, '-');
        getline(ss, firstLower, ',');
        getline(ss, secondUpper, '-');
        getline(ss, secondLower, ';');

        int firstUpperInt = stoi(firstUpper);
        int firstLowerInt = stoi(firstLower);
        int secondUpperInt = stoi(secondUpper);
        int secondLowerInt = stoi(secondLower);

        // if ((firstUpperInt <= secondUpperInt && firstLowerInt >= secondLowerInt) || (secondUpperInt <= firstUpperInt && secondLowerInt >=firstLowerInt))
        //     counter++;

        vector<int> firstVector;
        for (int i = firstUpperInt; i < firstLowerInt; i++) {
            firstVector.push_back(i);
        }

        for (auto i: firstVector) {
            cout << i << " ";
        }
        cout << endl;
        // vector<int> secondVector;
        // for (int j = secondUpperInt; j < secondLowerInt; j++) {
        //     secondVector.push_back(j);
        // }

        // for (int i = 0; i < firstVector.size(); i++) {
        //     for (int j = 0; secondVector.size(); j++) {
        //         if (firstVector[i] == secondVector[j]) {
        //             counter++;
        //         }
        //     }
        // }
    }

    cout << counter << endl;
}