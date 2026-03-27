/*
Algorithm:
1. Prompt user for input file name.
2. Open input file and read student records:
   - first name, last name, 4 test scores
3. Store records in a vector of structs.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

// Struct to store student data
struct Student {
    string firstName;
    string lastName;
    int test1, test2, test3, test4;
    double average;
    char grade;
};

int main() {
    vector<Student> students;
    string inputFile;
    
    // Prompt for input file
    cout << "Enter input file name: ";
    cin >> inputFile;

    ifstream inFile(inputFile);
    if (!inFile) {
        cout << "Error opening input file.\n";
        return 1;
    }

    // Read data
    Student s;
    while (inFile >> s.firstName >> s.lastName
                  >> s.test1 >> s.test2 >> s.test3 >> s.test4) {
        
        students.push_back(s);
    }

    inFile.close();
    for_each(begin(students), end(students), [](Student& s) {
        cout << s.firstName << endl;
    });
}