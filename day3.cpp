#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

int main() {
    fstream myFile;
    myFile.open("day3_input.txt", ios::in);

    if (!myFile.is_open()) {
        exit(EXIT_FAILURE);
    }

    vector<string> bags;
    string line;
    while(getline(myFile, line)) {
        bags.push_back(line);
    }

    for (auto i: bags) {
        cout << i << endl;
    }

    vector<string> firstHalf;
    vector<string> secondHalf;

    for (int i = 0; i < bags.size(); i++) {
        string currentBag = bags[i];

        for (int j = 0; j < currentBag.size()/2; j++) {
            firstHalf.push_back(currentBag[j]);
        }
    }

    for (auto i: firstHalf) {
        cout << i;
    }

    // for (int j = (bags.size()/2 + 1); j < bags.size(); j++) {
    //     secondHalf.push_back(bags[j]);
    // }

    
}