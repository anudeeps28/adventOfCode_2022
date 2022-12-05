#include<iostream>

#include<fstream>
#include<sstream>

#include<string>
#include<vector>

using namespace std;

int main() {
    fstream myFile;
    myFile.open("day2_input.txt", ios::in); // reading the file

    if (!myFile.is_open()) {
        exit(EXIT_FAILURE);
    }
   
    vector<string> result;
    string line;
    int lines;
    int totalScore = 0;

    while(getline(myFile, line)) {
        cout << line << endl;
        result.push_back(line);
        lines++;

        }

        cout << lines << endl;
        vector<pair<string, string>> data;
        string c1, c2;

        for (int i = 0; i < lines; i++) {
            stringstream ss(result[i]);
            ss >> c1 >> c2;

            cout << c1 << " " <<  c2 << endl;
            if (c1 == "A") {
                if (c2 == "X") totalScore += 3+1;
                if (c2 == "Y") totalScore += 6+2;
                if (c2 == "Z") totalScore += 0+3;

            }

            if (c1 == "B") {
                if (c2 == "X") totalScore += 0+1;
                if (c2 == "Y") totalScore += 3+2;
                if (c2 == "Z") totalScore += 6+3;

            }

            if (c1 == "C") {
                if (c2 == "X") totalScore += 6+1;
                if (c2 == "Y") totalScore += 0+2;
                if (c2 == "Z") totalScore += 3+3;

            }
        }

        cout << totalScore << endl;



        // for (int i = 0; i < lines; i++) {
        //     while (i != '\n') {
        //         stringstream inputString(line);

        //         for (int i = 0; i < result.size(); i++) {
        //             getline(inputString, data[i].first, ' ');
        //             getline(inputString, data[i].second, ' ');
        //         }

        //     for (int i = 0; i < data.size(); i++) {
        //     cout << data[i].first << " " << data[i].second << endl;
            
        //     }
        // }
        // }

        // cout << 2; 
        
}