#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    map<string, set<string>> studentClasses;

    // Add data
    studentClasses["Alice"].insert("Math");
    studentClasses["Alice"].insert("CS101");
    studentClasses["Alice"].insert("History");

    studentClasses["Bob"].insert("Physics");
    studentClasses["Bob"].insert("Math");

    // Ask user for student name
    string name;
    cout << "Enter student name: ";
    getline(cin, name);

    // Lookup student name in map and display classes
    auto it = studentClasses.find(name);

    if (it != studentClasses.end()) {
        cout << name << " is enrolled in:\n";
        for (const auto& course : it->second) {
            cout << "  " << course << endl;
        }
    } else {
        cout << "Student not found\n";
    }

    return 0;
}