/*
Algorithm:
4. For each student:
   - Compute average score
   - Determine letter grade
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

// Function to compute average
double computeAverage(const Student& s) {
    return (s.test1 + s.test2 + s.test3 + s.test4) / 4.0;
}

// Function to determine letter grade
char getGrade(double avg) {
    if      (avg >= 90) return 'A';
    else if (avg >= 80) return 'B';
    else if (avg >= 70) return 'C';
    else if (avg >= 60) return 'D';
    else                return 'F';
}

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
        s.average = computeAverage(s);
        s.grade = getGrade(s.average);

        students.push_back(s);
    }

    inFile.close();
    for_each(begin(students), end(students), [](Student& s) {
        cout << setw(10) << s.firstName << " " << setw(6) << setprecision(4) << s.average << " " << s.grade << endl;
    });
}