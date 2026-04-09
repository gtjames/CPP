#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

// https://open.kattis.com/problems/newalpha
//  HW9-HW-Map
int main(int argc, char *argv[])
{
    map<string, string> newAlpha;

    // Add data
    newAlpha["a"] = "@";
    newAlpha["b"] = "8";
    newAlpha["c"] = "(";
    newAlpha["d"] = "|)";
    newAlpha["e"] = "3";
    newAlpha["f"] = "#";
    newAlpha["g"] = "6";
    newAlpha["h"] = "[-]";
    newAlpha["i"] = "|";
    newAlpha["j"] = "_|";
    newAlpha["k"] = "|<";
    newAlpha["l"] = "1";
    newAlpha["m"] = "[]\\/[]";
    newAlpha["n"] = "[]\\[]";
    newAlpha["o"] = "0";
    newAlpha["p"] = "|D";
    newAlpha["q"] = "(,)";
    newAlpha["r"] = "|Z";
    newAlpha["s"] = "$";
    newAlpha["t"] = "']['";
    newAlpha["u"] = "|_|";
    newAlpha["v"] = "\\/";
    newAlpha["w"] = "\\/\\/";
    newAlpha["x"] = "}{";
    newAlpha["y"] = "`/";
    newAlpha["z"] = "2";

    string input;
    getline(cin, input);
    for (char c : input) {
        string s(1, tolower(c));
        if (newAlpha.find(s) != newAlpha.end()) {
            cout << newAlpha[s];
        } else {
            cout << c;
        }
    }
}