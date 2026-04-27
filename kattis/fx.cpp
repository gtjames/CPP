#include <iostream>
#include <set>
#include <sstream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    set<string> foxSounds;
    
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        
        size_t pos = line.find(" goes ");
        if (pos != string::npos) {
            string sound = line.substr(pos + 6);
            foxSounds.insert(sound);
        }
    }
    
    string sentence;
    getline(cin, sentence);
    
    istringstream iss(sentence);
    string word;
    bool first = true;
    
    while (iss >> word) {
        if (foxSounds.find(word) == foxSounds.end()) {
            if (!first) cout << " ";
            cout << word;
            first = false;
        }
    }
    cout << endl;
    
    return 0;
}