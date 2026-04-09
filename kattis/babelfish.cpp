#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

// https://open.kattis.com/problems/babelfish
//  HW9-HW-Map
int main() {
    map <string, string> dict;
    string line;
    while (getline(cin, line) && !line.empty()) {
        size_t spacePos = line.find(' ');
        string value = line.substr(0, spacePos);
        string key   = line.substr(spacePos + 1);
        dict[key] = value;
    }

    while (getline(cin, line) && !line.empty()) {
        if (dict.find(line) != dict.end()) {
            cout << dict[line] << endl;
        } else {
            cout << "eh" << endl;
        }
    }

    return 0;
}
