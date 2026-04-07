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
    int    test[4];
    double average;
    char grade;
};

struct Metric {
    double average;
    int max;
    int min;
};

// Function to determine letter grade
// ((int)avg / -10) + 10 + 'A' is a clever way to convert average to letter grade 
// without multiple if-else statements, but it can be less readable. 
// The if-else approach is more straightforward and easier to understand for most programmers.
char getGrade(double avg) {
//    cout << avg << " " << (char)(((int)avg / -10) + 9 + 'A') << endl; // Debugging line to show the calculated grade
    if      (avg >= 90) return 'A';     
    else if (avg >= 80) return 'B';
    else if (avg >= 70) return 'C';
    else if (avg >= 60) return 'D';
    else                return 'F';
}

// Sort function (descending order)
bool compareStudents(const Student& a, const Student& b) {
    return a.average > b.average;
}

int main() {
    vector<Student> students;
    vector<Metric> metrics(4); // One metric for each test
    int letterGrade[6] = {0}; // A, B, C, D, 'E', F counts
    string inputFile, outputFile;
    
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

    // Read data and compute averages and grades
    Student s;
    while (inFile >> s.firstName >> s.lastName
                  >> s.test[0] >> s.test[1] >> s.test[2] >> s.test[3]) {
        s.average = accumulate(begin(s.test), end(s.test), 0.0) / 4.0;
        s.grade = getGrade(s.average);
        letterGrade[s.grade-'A']++;

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
                << setw(8) << right << stu.test[0]
                << setw(8) << stu.test[1]
                << setw(8) << stu.test[2]
                << setw(8) << stu.test[3]
                << setw(8) << fixed << setprecision(2) << stu.average
                << setw(8) << stu.grade
                << endl;
    }
    outFile << setw(78) << setfill('*') << "" << setfill(' ') << endl;

    //  find ave, max and min for each test
    for (int i = 0; i < 4; ++i) {
        metrics[i].average = accumulate (students.begin(), students.end(), 0.0, [i](double sum, const Student& s) { return sum + s.test[i]; }) / students.size();
        metrics[i].max     = max_element(students.begin(), students.end(), [i](const Student& a, const Student& b) { return a.test[i] < b.test[i]; })->test[i];
        metrics[i].min     = min_element(students.begin(), students.end(), [i](const Student& a, const Student& b) { return a.test[i] < b.test[i]; })->test[i];
    }

    outFile << setw(30) << left << "Class Average: " << right << fixed << setprecision(2) << setw(8) << metrics[0].average << setw(8) << metrics[1].average << setw(8) << metrics[2].average << setw(8) << metrics[3].average << endl;
    outFile << setw(30) << left << "Class Max: "     << right << setw(8) << metrics[0].max << setw(8) << metrics[1].max  << setw(8) <<  metrics[2].max << setw(8) <<  metrics[3].max << endl;
    outFile << setw(30) << left << "Class Min: "     << right << setw(8) << metrics[0].min << setw(8) << metrics[1].min  << setw(8) <<  metrics[2].min << setw(8) <<  metrics[3].min << endl;
    outFile << setw(78) << setfill('=') << "" << setfill(' ') << endl;

    // Show letter grades
    for (int i = 0; i < 6; ++i) {
        if (i == 4) continue; // Skip 'E' grade
        letterGrade[i] = (static_cast<double>(letterGrade[i]) / static_cast<double>(students.size())) * 100; // Convert to percentage
        string gradeLabel = "Total " + string(1, 'A' + i) + "s: ";
        outFile << setw(26) << left << gradeLabel << right << fixed << setprecision(0) << setw(4) << letterGrade[i] << "%" << endl;
    }

    outFile << setw(78) << setfill('=') << "" << setfill(' ') << endl;
    outFile.close();

    cout << "Report generated successfully.\n";

    return 0;
}