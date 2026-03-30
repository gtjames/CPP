/*
Algorithm:
1. Prompt user for input file name.
2. Open input file and read student records:
   - first name, last name, 4 test scores
3. Store records in a vector of structs.
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string inputFile;
    string fileText;
    
    int test1, test2, test3, test4;
    string first, last;
    ifstream inFile("students.in");
    if (!inFile) {
        cout << "Error opening input file.\n";
        return 1;
    }

    // Read data
    while (inFile >> first >> last >> test1 >> test2 >> test3 >> test4) {
        cout << first << " " << last << " " << test1 << " " << test2 << " " << test3 << " " << test4 << endl;
    }
    inFile.close();
}