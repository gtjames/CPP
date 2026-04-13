#include <iostream>
#include <string>
#include <map>
#include <set>
#include <fstream>

using namespace std;

// https://open.kattis.com/problems/newalpha
//  HW9-HW-Map
int main(int argc, char *argv[]) {
    string encryptFile;
    map<string, string> newAlpha;
    string input;

    /** This is hard coded data and 
     * not the way you would want to do it in the real world 
     * */
    // Add data
    // newAlpha["a"] = "@";          
    // newAlpha["b"] = "8";         
    // newAlpha["c"] = "(";
    // newAlpha["d"] = "|)";         newAlpha["e"] = "3";         newAlpha["f"] = "#";
    // newAlpha["g"] = "6";          newAlpha["h"] = "[-]";       newAlpha["i"] = "|";
    // newAlpha["j"] = "_|";         newAlpha["k"] = "|<";        newAlpha["l"] = "1";
    // newAlpha["m"] = "[]\\/[]";    newAlpha["n"] = "[]\\[]";    newAlpha["o"] = "0";
    // newAlpha["p"] = "|D";         newAlpha["q"] = "(,)";       newAlpha["r"] = "|Z";
    // newAlpha["s"] = "$";          newAlpha["t"] = "']['";      newAlpha["u"] = "|_|";
    // newAlpha["v"] = "\\/";        newAlpha["w"] = "\\/\\/";    newAlpha["x"] = "}{";
    // newAlpha["y"] = "`/";         newAlpha["z"] = "2";
    
    //  If a file name is provided as a command line argument, 
    //  use that file instead of the default
    encryptFile = (argc > 1) ? argv[1] : encryptFile;

    //  Read the mapping from the file
    ifstream in(encryptFile);
    if (!in) {
        cerr << "Unable to open file " << encryptFile << endl;
        exit(1); // terminate with error
    }

    //  the encoding file is set up with each line 
    //     has a letter which is the key of our vector, separated by a space
    //     and the corresponding code which is the value
    string key, value;
    while (in >> key >> value) {
        newAlpha[key] = value;          // key/value. key/value over and over populating the vector
    }

    cout << "Enter text to encode: ";
    //  Use getline to read the entire line of input, including spaces, which is why we dpn't use cin >> input;
    getline(cin, input);
    for (char c : input) {
        string s(1, tolower(c));        //  force all characters to lowercase and convert char to string
        //        did we find the character before the end of the vector?
        //                  if we did, print the corresponding value, 
        //                                                          else print the original character
        cout << (newAlpha.find(s) != newAlpha.end() ? newAlpha[s] : s);
    }
    cout << endl;
    return 0;
}