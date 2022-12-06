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

    vector<string> data;
    string line;
    while(getline(myFile, line)) {
        data.push_back(line);
    }

    
    int finalScore = 0;
    for (int i = 0; i < data.size(); i++) {
        int half = data[i].size()/2;
        
        vector<char> left;
        vector<char> right;

        for (int j = 0; j < half; j++) {
            left.push_back(data[i][j]);
        }

        for (int j = half; j < data.size(); j++) {
            right.push_back(data[i][j]);
        }

        // for (auto i: left) {
        //     cout << i << " ";
        // }

        char commonChar;
        for (int i = 0; i < left.size(); i++) {
            for (int j = 0; j < right.size(); j++) {
                if (left[i] == right[j]) {
                    commonChar = left[i];
                }
            }
        }

        cout << commonChar << endl;

        int score = 0;
        if (int(commonChar) >= 97) {
            score += int(commonChar) - 96;
        }

        if (int(commonChar) < 97) {
            score += int(commonChar) - 38;
        }

        finalScore += score;

        left.clear();
        right.clear();

    }

    
    cout << finalScore;

    
}