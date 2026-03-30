#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string outputFile;
    string textToWrite;

    // Prompt for output file
    cout << "File name: ";
    cin >> outputFile;
    cin.ignore();           // Clear the NL from the input buffer

    // Open output file
    ofstream outFile(outputFile);
    if (!outFile) {
        cout << "Error opening output file.\n";
        return 1;
    }
    // Write data
    cout << "Text to write:\n";

    while (true) {
        getline(cin, textToWrite);
        if (textToWrite == "exit") {
            break;
        }
        outFile << textToWrite << endl;
    }

    outFile.close();
}