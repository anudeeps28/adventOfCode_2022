#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
#include<set>

using namespace std;

int main() {
    fstream myFile;
    myFile.open("day3_input.txt", ios::in);

    if (!myFile.is_open()) {
        exit(EXIT_FAILURE);
    }

    vector<string> data;
    string line;
    while(getline(myFile, line)) {
        data.push_back(line);
    }

    vector<int> score;   
    for (size_t i = 0; i < data.size(); i = i+3) {

        vector<string> groupOfThree;

        for (int k = 0; k < 3; k++) {
            groupOfThree.push_back(data[k+i]);
        }

        
        string first = groupOfThree[0];
        string second = groupOfThree[1];
        string third = groupOfThree[2];

        char target;
        vector<int> v1;
        vector<int> v2;
        vector<int> v3;
        
        for (size_t i = 0; i < first.size(); i++) {
            v1.push_back(int(first[i]));
        }

        for (size_t j = 0; j < second.size(); j++) {
            v2.push_back(int(second[j]));
        }

        for (size_t k = 0; k < third.size(); k++) {
            v3.push_back(int(third[k]));
        }
            
        for (size_t i = 0; i < v1.size(); i++) {
            for (size_t j = 0; j < v2.size(); j++) {
                for (size_t k = 0; k < v3.size(); k++) {
                    if (v1[i] == v2[j] && v1[i] == v3[k]) {
                        target = v1[i];
                    }

                }
            }

        }

        // cout << target;

        int currentScore = 0;
        if (122 >= int(target) && int(target) >= 97) {
            currentScore += int(target) - 96;
        }

        if (65 <= int(target) && int(target) <= 90) {
            currentScore += int(target) - 38;
        }

        cout << target << " " << int(target) << " " << currentScore << endl;
        score.push_back(currentScore);
   
    }
    int final = accumulate(score.begin(), score.end(), 0);
    cout << final;

    
    
}