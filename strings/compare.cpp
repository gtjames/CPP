// compare two strings to find a matching character at the same index
#include <iostream>
#include <string>

using namespace std;

int main() {
    std::string str1, str2;
    std::cout << "Enter first string: ";
    std::getline(std::cin, str1);
    std::cout << "Enter second string: ";
    std::getline(std::cin, str2);

    size_t minLength = std::min(str1.length(), str2.length());
    bool found = false;

    for (size_t i = 0; i < minLength; ++i) {
        if (str1[i] == str2[i]) {
            std::cout << "Matching character '" << str1[i] << "' at index " << i << std::endl;
            found = true;
            break; // Stop after finding the first match
        }
    }

    if (!found) {
        std::cout << "No matching characters at the same index." << std::endl;
    }

    string data = "ball";
    for (auto it = data.rbegin(); it != data.rend(); it++)
    {
        cout << char(toupper(*it));
    }

    // Write a function takes a string argument and returns true 
    // if the given string contains letter 'a' or 'A' otherwise returns false.
    auto containsA = [](const string& s) -> bool {
        for (char c : s) {
            if (tolower(c)    == 'a')  return true;
            if (c == 'a' || c == 'A')  return true;
        }
        return false;
    };

    // Write a complete C++ program that prompts user to enter their full name. 
    // Program then finds and prints the total number of vowels (a, e, i, o, u) in the provided name.
    std::string fullName;
    std::cout << "\nEnter your full name: ";
    std::getline(std::cin, fullName);

    int vowelCount = 0;
    for (char c : fullName) {
        char lower = std::tolower(c);
        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
            ++vowelCount;
        }
    }
    std::cout << "Total number of vowels in your name: " << vowelCount << std::endl;

    // Write a function that takes a string argument and 
    // returns the reverse of the string. E.g. 
    cin >> str1;
    auto reverseString = [](const string& s) -> string {
        string reversed;
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            reversed += *it;
        }
        return reversed;
    };
    auto reverseString = [](const string& s) -> string {
        string reversed;
        for (auto it = s.begin(); it != s.end(); ++it) {
            reversed = *it + reversed; // Prepend character to reverse the string
        }
        return reversed;
    };
    
    return 0;
}
