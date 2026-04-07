#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> addWords(const string &line)
{
    vector<string> words;
    stringstream ss(line);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

void findInMap(string prompt, const map<string, set<string>> &myMap) {
    string key;
    cout << prompt << endl;
    std::getline(cin, key);
    while (key.length() > 0) {
        auto it = myMap.find(key);
        if (it != myMap.end()) {
            cout << key << " is associated with:\n";
            for (const auto &value : it->second) {
                cout << "  " << value << endl;
            }
        } else {
            cout << key << " not found in map.\n";
        }
        cout << prompt << endl;
        std::getline(cin, key);
    }
}

void printMap(const string &title, const map<string, set<string>> &myMap) {
    cout << title << ":\n";
    for (const auto &item : myMap) {
        cout << item.first;
        for (const auto &value : item.second) {
            cout << " " << value;
        }
        cout << endl;
    }
}

int main(int argc, char *argv[]) {
    string line, student, theClass;
    map<string, set<string>> myClasses;
    map<string, set<string>> studentsInClass;
    
    cout << "Enter Student followed by classes" << endl;
    std::getline(cin, line);
    while (line.length() != 0) {
        vector<string> schedule = addWords(line);   //  break line into words and return as vector

        //get first item from vector and assign to student
        student = schedule[0];
        for (size_t i = 1; i < schedule.size(); i++) {      //  add student to class and class to student
            studentsInClass[schedule[i]].insert(student);
            myClasses[student].insert(schedule[i]);
        }
        std::getline(cin, line);
    }
    
    // Print the items and associated names
    printMap("Student and their Classes", myClasses);
    printMap("Class and their Students", studentsInClass);

    //  find students in a class
    cout << "Enter Class name to find students" << endl;
    std::getline(cin, theClass);
    while (theClass.length() > 0) {
        auto it = studentsInClass.find(theClass);
        if (it != studentsInClass.end()) {
            for (const auto &student : it->second) {
                cout << student << " ";
            }
        } else {
            cout << "Class not found: " << theClass << endl;
        }
        cout << "Enter Class name to find students" << endl;
        std::getline(cin, theClass);
    }

    // findInMap("Enter Student name to find Classes", myClasses);

    // find classes for a student
    cout << "Enter Student name to find Classes" << endl;
    std::getline(cin, student);
    while (student.length() > 0) {
        auto it = myClasses.find(student);
        if (it != myClasses.end()) {
            for (const auto &myClass : it->second) {
                    cout << myClass << " ";
            }
        } else {
            cout << "Student not found: " << student << endl;
        }
        cout << "Enter Student name to find Classes" << endl;
        std::getline(cin, student);
    }   
    return 0;
}
