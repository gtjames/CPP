#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Creating a vector
    vector<int> numbers;
    vector<string> names = {"Alice", "Bob", "Charlie"};
    vector<double> prices(5, 9.99); // 5 elements, all 9.99

    // Adding elements
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    
    names.push_back("Diana");
    names.insert(names.begin() + 1, "Zoe"); // Insert at position 1

    // Accessing elements
    cout << "First number: " << numbers[0] << endl;
    cout << "Second name: " << names.at(1) << endl;

    // Removing elements
    numbers.pop_back(); // Remove last element
    names.erase(names.begin() + 2); // Remove element at position 2
    numbers.clear(); // Remove all elements

    // Checking size
    cout << "Names size:   " << names.size() << endl;
    cout << "Numbers size: " << numbers.size() << endl;

    // Destroying vectors (automatic when they go out of scope)
    {
        vector<int> temp = {1, 2, 3};
        cout << "Temp vector size: " << temp.size() << endl;
    } // temp is automatically destroyed here

    //    delete[] prices.data(); // Manually freeing memory (not recommended, just for demonstration)
    return 0;
}