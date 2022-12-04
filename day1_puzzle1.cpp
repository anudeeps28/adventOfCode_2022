#include<iostream>
#include<map>
#include<fstream> // library needed to read the file
#include<cstdlib> // c standard library
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>


using namespace std;

int main() {
    fstream myFile;
    myFile.open("day1_puzzle1_input.txt", ios::in); // reading the file

    // test if the file is open
    if(!myFile.is_open()) {
        exit(EXIT_FAILURE); // comes from cstdlib
    }

    // if the file is open, take each line as a string input
    vector<string> result;
    string line;
    while(getline(myFile, line)) {
        result.push_back(line);
    }

    // for (auto i: result) {
    //     cout << i << endl;
    // }

    // convert string input to integer
    vector<vector<int>> Elf;
    Elf.push_back({});
    for (auto s: result) {
        if (s.size() > 0) {
            Elf.back().push_back(stoi(s));
        } 
        else {
            Elf.push_back({});
        }
    }


//    for (int i = 0; i < Elf.size(); i++) {
//         for (int j = 0; j < Elf[i].size(); j++) {
//             cout << Elf[i][j] << " ";
//         }

//         cout << endl;
//    }

    // convert to sum
    vector<int> vectorOfSums;
    int maxSum = 0;
    int i,j;
    for (i = 0; i < Elf.size(); i++) {
        vector<int> currentVector = Elf[i];
        int sum = accumulate(currentVector.begin(), currentVector.end(), 0);
        vectorOfSums.push_back(sum);
        if (sum > maxSum) {
            maxSum = sum;
        }
    }
    
    cout << maxSum << endl;

   


}