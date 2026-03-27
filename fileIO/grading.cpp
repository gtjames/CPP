/*
Algorithm:
1. Prompt user for input file name.
2. Open input file and read student records:
   - first name, last name, 4 test scores
3. Store records in a vector of structs.
4. For each student:
   - Compute average score
   - Determine letter grade
5. Sort students in descending order by average score.
6. Prompt user for output file name.
7. Write formatted report to output file:
   - Name, test scores, average, letter grade
8. Close files and exit program.
*/

/*
Programmer: Your Name
Course: CS112
Assignment: Student Grading System
Date: 

Description:
This program reads student test scores from a file, computes averages,
assigns letter grades, sorts students by average, and writes a report
to an output file.
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

// remove for now

void computeClassStats(const vector<Student>& students,
        double& highest, double& lowest, double& classAvg) {
    
    if (students.empty()) return;

    highest = students[0].average;
    lowest  = students[0].average;
    double sum = 0;

    // Find the student with the highest average
    auto topStudent = max_element(students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            return a.average < b.average;  // compares averages
        } );
    cout << topStudent->average << endl;

    for (const auto& s : students) {
        if (s.average > highest)
            highest = s.average;

        if (s.average < lowest)
            lowest = s.average;

        sum += s.average;
    }

    classAvg = sum / students.size();
}
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
    else return 'F';
}

// Sort function (descending order)
bool compareStudents(const Student& a, const Student& b) {
    return a.average > b.average;
}

int main() {
    vector<Student> students;
    string inputFile, outputFile;
    double highest, lowest, classAvg;
    
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

    // Sort students
    sort(students.begin(), students.end(), compareStudents);

    // Prompt for output file
    cout << "Enter output file name: ";
    cin >> outputFile;

    ofstream outFile(outputFile);
    if (!outFile) {
        cout << "Error opening output file.\n";
        return 1;
    }

    // Write header
    outFile << left << setw(12) << "First Name"
            << setw(12) << "Last Name"
            << setw(6) << "T1"
            << setw(6) << "T2"
            << setw(6) << "T3"
            << setw(6) << "T4"
            << setw(10) << "Average"
            << setw(6) << "Grade" << endl;

    outFile << "-------------------------------------------------------------\n";

    // Write student data
    for (const auto& stu : students) {
        outFile << left << setw(12) << stu.firstName
                << setw(12) << stu.lastName
                << setw(6) << stu.test1
                << setw(6) << stu.test2
                << setw(6) << stu.test3
                << setw(6) << stu.test4
                << setw(10) << fixed << setprecision(2) << stu.average
                << setw(6) << stu.grade << endl;
    }

    computeClassStats(students, highest, lowest, classAvg);

    outFile << "\n";
outFile << "Class Statistics\n";
outFile << "----------------\n";

outFile << "Highest Average: " << fixed << setprecision(2) << highest << endl;
outFile << "Lowest Average : " << fixed << setprecision(2) << lowest << endl;
outFile << "Class Average  : " << fixed << setprecision(2) << classAvg << endl;

string topStudent = students.front().firstName + " " + students.front().lastName;
string lowStudent = students.back().firstName + " " + students.back().lastName;
    outFile << "Top Student: " << topStudent << endl;
    outFile << "Low Student: " << lowStudent << endl;
    
    outFile.close();

    cout << "Report generated successfully.\n";

    return 0;
}