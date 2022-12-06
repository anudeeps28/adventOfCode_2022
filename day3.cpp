#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>

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


    vector<int> score = {};    
    for (int i = 0; i < data.size(); i++) {
        string word = data[i];
        int half = word.size()/2;
        
        vector<char> left = {};
        vector<char> right = {};

        for (int j = 0; j < half; j++) {
            left.push_back(word[j]);
        }

        for (int j = half; j < word.size(); j++) {
            right.push_back(word[j]);
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

        int currentScore = 0;
        if (122 >= int(commonChar) && int(commonChar) >= 97) {
            currentScore += int(commonChar) - 96;
        }

        if (65 <= int(commonChar) && int(commonChar) <= 90) {
            currentScore += int(commonChar) - 38;
        }

        cout << commonChar << " " << int(commonChar) << " " << currentScore << endl;
        score.push_back(currentScore);
        
        
        // cout << endl;
        left.clear();
        right.clear();

    }
   
    int final = accumulate(score.begin(), score.end(), 0);
    cout << final;

    
}