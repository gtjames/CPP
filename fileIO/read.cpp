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
#include <vector>
#include <algorithm>

using namespace std;

// Struct to store student data
struct Student {
    string firstName;
    string lastName;
    int    test1, test2, test3, test4;
    double average;
    char   grade;
};

// Sort function (descending order)
bool compareStudents(const Student& a, const Student& b) {
    return a.test1 > b.test1;
}

int main() {
    string inputFile;    
    string fileText;
    vector<Student> students;

    //  open file and set position to end of file
    ifstream inFile("students.in", ios::in | ios::ate);
    if (!inFile) {
        cout << "Error opening input file.\n";
        return 1;
    }

    // findout the size of the the file; get position in input sequence
    size_t size = inFile.tellg();
    cout << "Size of file: " << size << " bytes\n";
    // Set position in input sequence
    inFile.seekg(0, inFile.beg);

    // allocate memory to store file contents
    //  read the entire file into memory;
    char * buffer = new char[size];
    if (inFile.read(buffer, size)) {
        cout << "File contents...\n";
        cout << buffer << endl;
        // parse buffer in memory...
    }
    delete[] buffer;

    inFile.seekg(0, inFile.beg);

    Student s;
    s.average = 66.6;
    // Read data
    while (inFile >> s.firstName >> s.lastName >> s.test1 >> s.test2 >> s.test3 >> s.test4) {
        cout    << setw(10) << left  << s.firstName << " " << setw(10) << left  << s.lastName << " " 
                << setw(5)  << right << s.test1     << " " << setw(5)  << right << s.test2 << " " 
                << setw(5)  << right << s.test3     << " " << setw(5)  << right << s.test4 << " " 
                << setw(8)  << fixed << setprecision(2) << s.average << " " << setw(5) << right << s.grade << endl;
                s.average = (s.test1 + s.test2 + s.test3 + s.test4) / 4.0;
        students.push_back(s);
    }
    inFile.close();

    // Sort students
    std::sort(students.begin(), students.end(), compareStudents);
    Student stu = students.back();

    cout << "\nLowest Test1 score:\n";
    cout    << setw(10) << left  << stu.firstName << " " << setw(10) << left  << stu.lastName << " " 
            << setw(5)  << right << stu.test1     << " " << setw(5)  << right   << stu.test2 << " " 
            << setw(5)  << right << stu.test3     << " " << setw(5)  << right   << stu.test4 << " " 
            << setw(8)  << fixed << setprecision(2) << stu.average << " " << setw(5) << right << stu.grade << endl; 
}