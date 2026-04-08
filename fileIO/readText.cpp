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

using namespace std;

int main() {
    string inputFile;
    string fileText;
    
    // Prompt for input file
    cout << "Enter input file name: ";
    cin >> inputFile;

    // char ch;
    // file.get(ch);
    // string line;
    // getline(file, line);

    // file.tellg();                // for reading. GET the current position of the file pointer
    // file.tellp();                // for writing. Where will be PUT the next character

    // file.seekg(0);               // go to beginning
    // file.seekg(10, ios::beg);    // move to position 10

    // ios::app                     // Append
    // ios::trunc                   // Truncate file to zero length

    // file.fail();                 // operation failed
    // file.eof();                  // reached end of file
    // file.good();                 // everything OK

    //      if (inFile.is_open()) {
    //          cout << "File opened!" << endl;
    //      }

    // File open modes: 
    //          fstream file("data.txt", ios::in | ios::out);
    // Mode         Meaning
    // ios::in      Read
    // ios::out     Write
    // ios::app     Append
    // ios::trunc   Overwrite
    // ios::binary  Binary


    ifstream inFile(inputFile);
    if (!inFile) {
        cout << "Error opening input file.\n";
        return 1;
    }

    // Read data
    int wordCnt = 0, charCnt = 0, lineCnt = 0;
    while (getline(inFile, fileText)) {
        // int location = inFile.tellg(); // Get the current position of the file pointer
        // std::cout << location << fileText << std::endl;
        lineCnt++;
        charCnt += fileText.length();
        wordCnt += count(fileText.begin(), fileText.end(), ' ') + 1;

        // Process each line of the file
        if (fileText.find("if ") != string::npos) {
           cout << fileText << endl; // Print the line to the console
        }
    }
    cout << "# Lines: " << lineCnt << ", Words: " << wordCnt << ", Characters: " << charCnt << std::endl;
    inFile.close();
}