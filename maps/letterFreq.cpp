
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
    map <string, int> letterFreq;
    string inputFile;
    string word;

    cout << "Enter input file name: ";
    cin >> inputFile;
    ifstream inFile(inputFile);
    ofstream five("5.out");

    while (inFile >> word) {
        for (char c : word) {
            letterFreq[string(1, c)]++;
        }
        if (word.length() == 5)
            five << word << endl; 
    }

    for (const auto &pair : letterFreq) {
        cout << pair.first << ": " << pair.second << endl;
    }


    ofstream outFile("frequency.out");
    for (const auto &pair : letterFreq) {
        outFile << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
