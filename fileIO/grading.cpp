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
#include <functional>

#include <numeric>
#include <ranges>

using namespace std;

// Struct to store student data
struct Student {
    string firstName;
    string lastName;
    int    test1, test2, test3, test4;
    double average;
    char   grade;
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
    if(inputFile.length() == 1)
        inputFile = "students.in";

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
    outFile << setw(78) << setfill('=') << "" << setfill(' ') << endl;
    outFile << setw(15) << left << "First Name"
            << setw(15) << "Last Name"
            << setw(8) << right << "T1"
            << setw(8) << "T2"
            << setw(8) << "T3"
            << setw(8) << "T4"
            << setw(8) << "Average"
            << setw(8) << "Grade" << endl;
        
    outFile << setw(78) << setfill('=') << "" << setfill(' ') << endl;

    // Write student data
for (const auto& stu : students) {
    outFile << setw(15) << left << stu.firstName
            << setw(15)         << stu.lastName
            << right << setw(8) << stu.test1
            << setw(8) << stu.test2
            << setw(8) << stu.test3
            << setw(8) << stu.test4
            << setw(8) << fixed << setprecision(2) << stu.average
            << setw(8) << stu.grade
            << endl;
    }
    outFile << setw(78) << setfill('*') << "" << setfill(' ') << endl;

    computeClassStats(students, highest, lowest, classAvg);

    //  find ave for each test
    double test1 = accumulate(students.begin(), students.end(), 0.0, [](double sum, const Student& s) { return sum + s.test1; }) / students.size();
    double test2 = accumulate(students.begin(), students.end(), 0.0, [](double sum, const Student& s) { return sum + s.test2; }) / students.size();
    double test3 = accumulate(students.begin(), students.end(), 0.0, [](double sum, const Student& s) { return sum + s.test3; }) / students.size();
    double test4 = accumulate(students.begin(), students.end(), 0.0, [](double sum, const Student& s) { return sum + s.test4; }) / students.size();

    //  find max and min for each test
    int max1 = max_element(students.begin(), students.end(), [](const Student& a, const Student& b) { return a.test1 < b.test1; })->test1;
    int max2 = max_element(students.begin(), students.end(), [](const Student& a, const Student& b) { return a.test2 < b.test2; })->test2;
    int max3 = max_element(students.begin(), students.end(), [](const Student& a, const Student& b) { return a.test3 < b.test3; })->test3;
    int max4 = max_element(students.begin(), students.end(), [](const Student& a, const Student& b) { return a.test4 < b.test4; })->test4;

    int min1 = min_element(students.begin(), students.end(), [](const Student& a, const Student& b) { return a.test1 < b.test1; })->test1;
    int min2 = min_element(students.begin(), students.end(), [](const Student& a, const Student& b) { return a.test2 < b.test2; })->test2;
    int min3 = min_element(students.begin(), students.end(), [](const Student& a, const Student& b) { return a.test3 < b.test3; })->test3;
    int min4 = min_element(students.begin(), students.end(), [](const Student& a, const Student& b) { return a.test4 < b.test4; })->test4;

    outFile << setw(30) << left << "Class Average: " << right << fixed << setprecision(2) << setw(8) << test1 << setw(8) << test2 << setw(8) << test3 << setw(8) << test4 << endl;
    outFile << setw(30) << left << "Class Max: "     << right << setw(8) << max1 << setw(8) << max2  << setw(8) <<  max3 << setw(8) <<  max4 << endl;
    outFile << setw(30) << left << "Class Min: "     << right << setw(8) << min1 << setw(8) << min2  << setw(8) <<  min3 << setw(8) <<  min4 << endl;
    outFile << setw(78) << setfill('=') << "" << setfill(' ') << endl;

    double aCnt = count_if(students.begin(), students.end(), [](const Student& s) { return s.grade == 'A'; }) / static_cast<double>(students.size());
    double bCnt = count_if(students.begin(), students.end(), [](const Student& s) { return s.grade == 'B'; }) / static_cast<double>(students.size());
    double cCnt = count_if(students.begin(), students.end(), [](const Student& s) { return s.grade == 'C'; }) / static_cast<double>(students.size());
    double dCnt = count_if(students.begin(), students.end(), [](const Student& s) { return s.grade == 'D'; }) / static_cast<double>(students.size());
    double fCnt = count_if(students.begin(), students.end(), [](const Student& s) { return s.grade == 'F'; }) / static_cast<double>(students.size());

    // Total As:                   36%
    // Total Bs:                   27%
    outFile << setw(26) << left << "Total As: " << right << fixed << setprecision(0) << setw(4) << aCnt * 100 << "%" << endl;
    outFile << setw(26) << left << "Total Bs: " << right << fixed << setprecision(0) << setw(4) << bCnt * 100 << "%" << endl;
    outFile << setw(26) << left << "Total Cs: " << right << fixed << setprecision(0) << setw(4) << cCnt * 100 << "%" << endl;
    outFile << setw(26) << left << "Total Ds: " << right << fixed << setprecision(0) << setw(4) << dCnt * 100 << "%" << endl;
    outFile << setw(26) << left << "Total Fs: " << right << fixed << setprecision(0) << setw(4) << fCnt * 100 << "%" << endl;

    outFile << setw(78) << setfill('=') << "" << setfill(' ') << endl;
    outFile.close();

    cout << "Report generated successfully.\n";

    return 0;
}