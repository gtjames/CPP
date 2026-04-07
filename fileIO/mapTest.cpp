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

int main(int argc, char *argv[]) {
    string line, student, theClass;
    map<string, set<string>> myClasses;
    map<string, set<string>> studentsInClass;
    
    cout << "Enter Student followed by classes" << endl;
    getline(cin, line);
    while (line != "") {
        vector<string> schedule = addWords(line);
        //get first item from vector and assign to student
        student = schedule[0];
        for (size_t i = 1; i < schedule.size(); i++) {
            studentsInClass[schedule[i]].insert(student);
            myClasses[schedule[i]].insert(student);
        }
        getline(cin, line);
    }
    // Print the items and associated namespring
    for (const auto &item : myClasses) {
        cout << item.first;
        for (const auto &name : item.second) {
            cout << " " << name;
        }
        cout << endl;
    }
    cout << "Enter Class name to find students" << endl;
    getline(cin, theClass);
    while (theClass != "") {
        set<string> s = studentsInClass[theClass];
        for (const auto &item : s) {
                cout << item << " ";
        }
        cout << endl;
        getline(cin, theClass);
    }
    cout << "Enter Student name to find Classes" << endl;
    getline(cin, student);
    while (student != "") {
        set<string> s = myClasses[student];
        for (const auto &item : s) {
                cout << item << " ";
        }
        cout << endl;
        getline(cin, theClass);
    }
    return 0;
}
